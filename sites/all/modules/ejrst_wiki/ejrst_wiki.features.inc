<?php
/**
 * @file
 * ejrst_wiki.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ejrst_wiki_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ejrst_wiki_node_info() {
  $items = array(
    'wiki' => array(
      'name' => t('Wiki'),
      'base' => 'node_content',
      'description' => t('Adds more or less permanent pages that contain information about a specific issue that may be updated. All wiki articles should have revisions.'),
      'has_title' => '1',
      'title_label' => t('Topic'),
      'help' => '',
    ),
  );
  return $items;
}
