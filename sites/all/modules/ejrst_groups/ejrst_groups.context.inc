<?php
/**
 * @file
 * ejrst_groups.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ejrst_groups_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'group_home_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'groups' => 'groups',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-my_groups-block_1' => array(
          'module' => 'views',
          'delta' => 'my_groups-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-groups-block_1' => array(
          'module' => 'views',
          'delta' => 'groups-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['group_home_page'] = $context;

  return $export;
}
