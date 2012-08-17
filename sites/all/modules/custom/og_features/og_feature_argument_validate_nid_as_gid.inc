<?php

class og_feature_argument_validate_nid_as_gid extends og_viewscontext_argument_validate_nid_as_gid {
  function option_definition() {
    $options = parent::option_definition();
    $options['group_feature'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['group_feature'] = array(
      '#type' => 'select',
      '#title' => t("Group Feature"),
      '#description' => t('Group feature that must be enabled in order for this to validate'),
      '#default_value' => $this->options['group_feature'],
      '#options' => og_features_select_list(),
    );
  }

  function validate_argument($argument) {
    $parent = parent::validate_argument($argument);
    if ($parent) {
      $group = og_get_group($this->options['entity_type'], $argument);
      return og_features_is_enabled($group, $this->options['group_feature']);
    }
    else return FALSE;
  }
}
