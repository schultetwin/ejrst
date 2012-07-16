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

  $view = new view();
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
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<a href="/node/add/discussion?field_discussion_article=!1">Create New Discussion</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No discussions found for %1';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = '';
  $handler->display->display_options['fields']['new_comments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['new_comments']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['format_plural_singular'] = '1 new comment';
  $handler->display->display_options['fields']['new_comments']['format_plural_plural'] = '@count new comments';
  $handler->display->display_options['fields']['new_comments']['prefix'] = '(';
  $handler->display->display_options['fields']['new_comments']['suffix'] = ')';
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
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['types'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['access'] = TRUE;
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
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Article (field_discussion_article) */
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['id'] = 'field_discussion_article_target_id';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['table'] = 'field_data_field_discussion_article';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['field'] = 'field_discussion_article_target_id';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['types'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['arguments']['field_discussion_article_target_id']['validate_options']['access'] = TRUE;
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
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
  );
  $export['article_discussions'] = $view;

  return $export;
}
