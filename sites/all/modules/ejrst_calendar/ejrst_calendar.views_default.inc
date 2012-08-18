<?php
/**
 * @file
 * ejrst_calendar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ejrst_calendar_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'group_calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Group Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'blog' => '#ffffff',
    'discussion' => '#ffffff',
    'event' => '#ffffff',
    'group' => '#ffffff',
    'journal' => '#ffffff',
    'news' => '#ffffff',
    'notes' => '#ffffff',
    'resource' => '#ffffff',
    'tasks' => '#ffffff',
    'wiki' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_group'] = array(
    1 => '#ffffff',
    2 => '#ffffff',
    3 => '#ffffff',
    4 => '#ffffff',
    5 => '#ffffff',
    6 => '#ffffff',
    7 => '#ffffff',
    8 => '#ffffff',
    9 => '#ffffff',
    10 => '#ffffff',
    11 => '#ffffff',
    12 => '#ffffff',
  );
  /* Header: Global: Add Content Link */
  $handler->display->display_options['header']['add_content_link']['id'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['table'] = 'views';
  $handler->display->display_options['header']['add_content_link']['field'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['empty'] = FALSE;
  $handler->display->display_options['header']['add_content_link']['bundle'] = 'event';
  $handler->display->display_options['header']['add_content_link']['into_group'] = 1;
  $handler->display->display_options['header']['add_content_link']['link_title'] = 'Add New Event';
  $handler->display->display_options['header']['add_content_link']['link_perm'] = 'create event content';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No Events for this Group';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_event_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_event_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_event_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_event_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_event_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_event_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_event_location']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Groups audience (group_audience:gid) */
  $handler->display->display_options['arguments']['group_audience_gid']['id'] = 'group_audience_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['table'] = 'field_data_group_audience';
  $handler->display->display_options['arguments']['group_audience_gid']['field'] = 'group_audience_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group_audience_gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group_audience_gid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['group_audience_gid']['validate']['type'] = 'og_features_nid_as_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['must_be_member'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['set_group_context'] = '1';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['group_feature'] = 'events';
  $handler->display->display_options['arguments']['group_audience_gid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['not'] = 0;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_date.field_event_date_value' => 'field_data_field_event_date.field_event_date_value',
  );
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
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/events';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['group_calendar'] = array(
    t('Master'),
    t('Calendar'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No Events for this Group'),
    t('Location'),
    t('All'),
    t('Page'),
  );
  $export['group_calendar'] = $view;

  return $export;
}
