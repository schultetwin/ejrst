<?php
/**
 * @file
 * ejrst_discussions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ejrst_discussions_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'article_discussions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Article Discussions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Article Discussions';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'new_comments' => 'new_comments',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/node/add/discussion?field_discussion_article=!1">Create New Discussion</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No discussions found for %1';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
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
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = '';
  $handler->display->display_options['fields']['new_comments']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['external'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['html'] = 0;
  $handler->display->display_options['fields']['new_comments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['new_comments']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = 0;
  $handler->display->display_options['fields']['new_comments']['empty_zero'] = 0;
  $handler->display->display_options['fields']['new_comments']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['new_comments']['format_plural'] = 1;
  $handler->display->display_options['fields']['new_comments']['format_plural_singular'] = '1 new comment';
  $handler->display->display_options['fields']['new_comments']['format_plural_plural'] = '@count new comments';
  $handler->display->display_options['fields']['new_comments']['prefix'] = '(';
  $handler->display->display_options['fields']['new_comments']['suffix'] = ')';
  $handler->display->display_options['fields']['new_comments']['link_to_comment'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'year';
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  /* Contextual filter: Content: Article (field_discussion_article) */
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['id'] = 'field_discussion_article_target_id';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['table'] = 'field_data_field_discussion_article';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['field'] = 'field_discussion_article_target_id';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['types'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['access'] = '1';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['not'] = 0;
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
    'discussion' => 'discussion',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Article (field_discussion_article) */
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['id'] = 'field_discussion_article_target_id';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['table'] = 'field_data_field_discussion_article';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['field'] = 'field_discussion_article_target_id';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['types'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['access'] = '1';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['not'] = 0;
  $handler->display->display_options['path'] = 'node/%/discussions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Discussions';
  $handler->display->display_options['menu']['description'] = 'Discussions on this article';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['article_discussions'] = array(
    t('Master'),
    t('Article Discussions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="/node/add/discussion?field_discussion_article=!1">Create New Discussion</a>'),
    t('No discussions found for %1'),
    t('.'),
    t(','),
    t('('),
    t(')'),
    t('All'),
    t('Block'),
    t('Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
  );
  $export['article_discussions'] = $view;

  $view = new view;
  $view->name = 'group_discussions';
  $view->description = 'List of discussions in a group';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Group Discussions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Discussions';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Add Content Link */
  $handler->display->display_options['header']['add_content_link']['id'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['table'] = 'views';
  $handler->display->display_options['header']['add_content_link']['field'] = 'add_content_link';
  $handler->display->display_options['header']['add_content_link']['empty'] = TRUE;
  $handler->display->display_options['header']['add_content_link']['bundle'] = 'discussion';
  $handler->display->display_options['header']['add_content_link']['into_group'] = 1;
  $handler->display->display_options['header']['add_content_link']['link_title'] = 'Add New Discussion';
  $handler->display->display_options['header']['add_content_link']['link_perm'] = 'create discussion content';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No discussions in this group';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 1;
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
    'trim_length' => '600',
  );
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['format_plural_singular'] = '1 comment';
  $handler->display->display_options['fields']['comment_count']['format_plural_plural'] = '@count comments';
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['empty'] = '0 new comments';
  $handler->display->display_options['fields']['new_comments']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['format_plural_singular'] = '1 new comment';
  $handler->display->display_options['fields']['new_comments']['format_plural_plural'] = '@count new comments';
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
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['group_audience_gid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group_audience_gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group_audience_gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group_audience_gid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['group_audience_gid']['validate']['type'] = 'og_features_nid_as_gid';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['must_be_member'] = 0;
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['set_group_context'] = '1';
  $handler->display->display_options['arguments']['group_audience_gid']['validate_options']['group_feature'] = 'discussion';
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
    'discussion' => 'discussion',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/group_discussions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Discussions';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['group_discussions'] = array(
    t('Master'),
    t('Discussions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No discussions in this group'),
    t('Comments'),
    t('.'),
    t(','),
    t('New comments'),
    t('0 new comments'),
    t('All'),
    t('Page'),
  );
  $export['group_discussions'] = $view;

  return $export;
}
