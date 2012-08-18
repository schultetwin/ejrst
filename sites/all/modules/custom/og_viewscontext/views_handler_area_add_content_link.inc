<?php

class views_handler_area_add_content_link extends views_handler_area {
  function option_definition() {
    $options = parent::option_definition();

    $options['bundle'] = array('default' => '');
    $options['into_group'] = array('default' => FALSE);
    $options['link_title'] = array('default' => '');
    $options['link_perm'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['bundle'] = array(
      '#type' => 'select',
      '#title' => t('Content Type'),
      '#default_value' => $this->options['bundle'],
      '#description' => t('Choose what type of node you would like to create a link for'),
      '#options' => node_type_get_names(),
    );
    $form['link_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Link Title'),
      '#default_value' => $this->options['link_title'],
      '#description' => t('Enter the text you want to display as the link'),
    );
    $form['into_group'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Group Context to Post Node Into Group'),
      '#default_value' => $this->options['into_group'],
    );
    $options = array();
    $options[] = t('- None -');
    $perms = og_get_permissions();
    foreach ($perms as $perm => $info) {
      $options[$perm] = $info['title'];
    }
    $form['link_perm'] = array(
      '#type' => 'select',
      '#title' => t('Show only if user has group permission'),
      '#default_value' => $this->options['link_perm'],
      '#options' => $options,
      '#states' => array(
        'visible' => array(
          ':input[name="options[into_group]"]' => array('checked' => TRUE),
        ),
        'invisible' => array(
          ':input[name="options[into_group]"]' => array('checked' => FALSE),
        ),
      ),
    );
  }
  function render($empty = FALSE) {
    $options = array();
    if (!$empty || $this->options['empty']) {
      if ($this->options['into_group'] && $group = og_context()) {
        if ($this->options['link_perm'] != '0' && !og_user_access($group->gid, $this->options['link_perm'])) {
          return;
        }
      }

      $link = 'node/add/' . str_replace('_', '-', $this->options['bundle']);
      if (drupal_valid_path($link)) {
        return '<div class="views-header-content-link">' . l($this->options['link_title'], $link, $options) . '</div>';
      }
    }
  }
}
