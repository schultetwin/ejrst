<?php
/**
 * @file
 * ejrst_discussions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ejrst_discussions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ejrst_discussions_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ejrst_discussions_node_info() {
  $items = array(
    'discussion' => array(
      'name' => t('Discussion'),
      'base' => 'node_content',
      'description' => t('Discussions occur about articles or about general '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
