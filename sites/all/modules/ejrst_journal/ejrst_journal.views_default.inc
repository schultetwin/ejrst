<?php
/**
 * @file
 * ejrst_journal.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ejrst_journal_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'issues_in_journal';
  $view->description = 'Lists all issues in a journal (given argument of nid of journal). This is programmatically added to the view';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Issues In Journal';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Articles in Journal';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No articles found in journal';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
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
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_article_author']['id'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['table'] = 'field_data_field_article_author';
  $handler->display->display_options['fields']['field_article_author']['field'] = 'field_article_author';
  $handler->display->display_options['fields']['field_article_author']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_article_author']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_article_author']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Wiley ID */
  $handler->display->display_options['fields']['field_article_wiley_id']['id'] = 'field_article_wiley_id';
  $handler->display->display_options['fields']['field_article_wiley_id']['table'] = 'field_data_field_article_wiley_id';
  $handler->display->display_options['fields']['field_article_wiley_id']['field'] = 'field_article_wiley_id';
  $handler->display->display_options['fields']['field_article_wiley_id']['label'] = 'View in Wiley';
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['path'] = 'http://onlinelibrary.wiley.com/doi/10.1002/[field_article_wiley_id-value]/abstract';
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['alt'] = 'View in Wiley';
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_article_wiley_id']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_article_wiley_id']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_article_wiley_id']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_article_wiley_id']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_article_wiley_id']['settings'] = array(
    'trim_length' => '20',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Journal (field_article_journal) */
  $handler->display->display_options['arguments']['field_article_journal_target_id']['id'] = 'field_article_journal_target_id';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['table'] = 'field_data_field_article_journal';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['field'] = 'field_article_journal_target_id';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_article_journal_target_id']['summary_options']['items_per_page'] = '25';
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
    'article' => 'article',
  );
  $translatables['issues_in_journal'] = array(
    t('Master'),
    t('Articles in Journal'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No articles found in journal'),
    t('Author'),
    t('View in Wiley'),
    t('http://onlinelibrary.wiley.com/doi/10.1002/[field_article_wiley_id-value]/abstract'),
    t('_blank'),
    t('All'),
  );
  $export['issues_in_journal'] = $view;

  return $export;
}
