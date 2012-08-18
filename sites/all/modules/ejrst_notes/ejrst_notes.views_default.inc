<?php
/**
 * @file
 * ejrst_notes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ejrst_notes_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'group_notes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Group Notes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group Notes';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Add Content Link */
  $handler->display->display_options['header']['add_content_link']['id'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['table'] = 'views';
  $handler->display->display_options['header']['add_content_link']['field'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['empty'] = TRUE;
  $handler->display->display_options['header']['add_content_link']['bundle'] = 'notes';
  $handler->display->display_options['header']['add_content_link']['into_group'] = 1;
  $handler->display->display_options['header']['add_content_link']['link_title'] = 'Add New Note';
  $handler->display->display_options['header']['add_content_link']['link_perm'] = 'create notes content';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No notes in group';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Groups audience (group_audience:gid) */
  $handler->display->display_options['arguments']['group_audience_gid']['id'] = 'group_audience_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['table'] = 'field_data_group_audience';
  $handler->display->display_options['arguments']['group_audience_gid']['field'] = 'group_audience_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group_audience_gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group_audience_gid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['group_audience_gid']['validate']['type'] = 'og_features_nid_as_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['must_be_member'] = '1';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['set_group_context'] = '1';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['group_feature'] = 'note';
  $handler->display->display_options['arguments']['group_audience_gid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'notes' => 'notes',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/notes';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Notes';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['group_notes'] = array(
    t('Master'),
    t('Group Notes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No notes in group'),
    t('All'),
    t('Page'),
  );
  $export['group_notes'] = $view;

  return $export;
}
