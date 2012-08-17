<?php
/**
 * @file
 * ejrst_notes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ejrst_notes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ejrst_notes_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ejrst_notes_node_info() {
  $items = array(
    'notes' => array(
      'name' => t('Notes'),
      'base' => 'node_content',
      'description' => t('Notes are a simple content types for groups to have "quick notes" to record.'),
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
  );
  return $items;
}
