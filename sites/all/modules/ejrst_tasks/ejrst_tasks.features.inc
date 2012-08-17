<?php
/**
 * @file
 * ejrst_tasks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ejrst_tasks_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ejrst_tasks_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ejrst_tasks_node_info() {
  $items = array(
    'tasks' => array(
      'name' => t('Tasks'),
      'base' => 'node_content',
      'description' => t('Tasks are things that are assigned to people to get done.'),
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => '',
    ),
  );
  return $items;
}
