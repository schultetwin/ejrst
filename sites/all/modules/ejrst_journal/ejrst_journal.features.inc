<?php
/**
 * @file
 * ejrst_journal.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ejrst_journal_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ejrst_journal_node_info() {
  $items = array(
    'journal' => array(
      'name' => t('Journal'),
      'base' => 'node_content',
      'description' => t('A published journal. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
