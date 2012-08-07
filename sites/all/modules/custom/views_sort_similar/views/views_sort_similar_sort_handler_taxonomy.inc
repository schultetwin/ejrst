<?php

class views_sort_similar_sort_handler_taxonomy extends views_handler_sort {

  var $tids = array();

  function can_expose() {
    return FALSE;
  }

  function option_definition() {
    global $user;
    $options = parent::option_definition();
    $options['user_tax_fields'] = array('default' => array());
    $options['user_uid'] = array('default' => $user->uid);
    $options['user_id_from_arg'] = array('default' => null);
    $options['user_uid_origin'] = array('default' => '');
    $options['order'] = array('default' => 'DESC');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['user_tax_fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('User Taxonomy Fields'),
      '#description' => t('User taxonomy fields to pull the tids from'),
      '#default_value' => $this->options['user_tax_fields'],
      '#options' => _views_sort_similiar_user_tax_fields(),
    );

    $form['user_uid_origin'] = array(
      '#type' => 'select',
      '#title' => t('User ID Origin'),
      '#description' => t('Where do we get the origin of the UID?'),
      '#default_value' => $this->options['user_uid_origin'],
      '#options' => array(
        'logged_in_user' => t('Logged On User'),
        'arg' => t('Contextual Filter'),
        'static' => t('Given User Id'),
      ),
    );

    $form['user_uid'] = array(
      '#type' => 'textfield',
      '#title' => t('User UID'),
      '#states' => array(
        'visible' => array(
          ':input[name="options[user_uid_origin]"]' => array('value' => 'static'),
        ),
        'invisible' => array(
          ':input[name="options[user_uid_origin]"]' => array(array('value' => 'arg'), array('value' => 'logged_in_user')),
        )
      ),
      '#description' => t('Enter the UID of the user you want to use'),
      '#default_value' => $this->options['user_uid'],
      '#size' => 4,
    );

    $form['user_id_from_arg'] = array(
      '#type' => 'textfield',
      '#title' => t('UID from Contextual Filter'),
      '#description' => t('Get UID from a contextual filter, %1 = first,  %2 = second'),
      '#default_value' => $this->options['user_id_from_arg'],
      '#size' => 4,
      '#states' => array(
        'visible' => array(
          ':input[name="options[user_uid_origin]"]' => array('value' => 'arg'),
        ),
        'invisible' => array(
          ':input[name="options[user_uid_origin]"]' => array(array('value' => 'static'), array('value' => 'logged_in_user')),
        )
      ),
    );
  }

  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    if ($form_state['values']['options']['user_uid_origin'] == 'static') {
      $user = user_load($form_state['values']['options']['user_uid']);
      if (!is_object($user)) {
        form_set_error('user_uid', t('Must enter a valid UID'));
      }
    }
  }

  function sort_options() {
    $options = parent::sort_options();
    $options['ASC'] = t('Least Similiar');
    $options['DESC'] = t('Most Similiar');
    return $options;
  }

  function pre_query() {
    parent::pre_query();
    global $user;
    $uid = null;
    switch ($this->options['user_uid_origin']) {
      case 'logged_in_user':
        $uid = $user->uid;
        break;
      case 'arg':
        throw new Exception("Not implemented yet");
        break;
      case 'static':
        $uid = $this->options['user_uid'];
        break;
      default:
        throw new Exception("No UID options given");
        break;
    }
     if (!is_array($this->options['user_tax_fields'])) $this->options['user_tax_fields'] = array();
    $this->tids = _views_sort_similar_get_tids($this->options['user_tax_fields'], $uid);
  }

  function query() {
    //$table_alias = $this->query->ensure_table('taxonomy_index', $this->relationship);
    //$subquery = db_select('taxonomy_index', 'tn');
    //$subquery->addField('tn', 'nid');
    //$subquery->where('tn.nid = node.nid');
    //$subquery->condition('tid', $this->tids, 'IN');
    //$subquery->where('tn.tid IN ' . implode(', ', $this->tids));
    //$count = $subquery->countQuery();
    $tids = implode(', ', $this->tids);
    $count = "(SELECT COUNT(*) FROM {taxonomy_index} tn WHERE tn.nid = node.nid AND tn.tid IN($tids))";
    $this->query->add_orderby(null,  $count, $this->options['order'], 'views_tax_subquery', array());
  }
}
