<?php
/**
 * @file
 * ejrst_articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ejrst_articles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ejrst_articles_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function ejrst_articles_flag_default_flags() {
  $flags = array();
  // Exported flag: "Featured".
  $flags['featured_article'] = array(
    'content_type' => 'node',
    'title' => 'Featured',
    'global' => '1',
    'types' => array(
      0 => 'article',
    ),
    'flag_short' => 'Feature',
    'flag_long' => 'Add this article to featured list',
    'flag_message' => 'Featured',
    'unflag_short' => 'Unfeature',
    'unflag_long' => 'Remote this article from featured lists',
    'unflag_message' => 'Article no longer featured.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '3',
        1 => '4',
      ),
      'unflag' => array(
        0 => '3',
        1 => '4',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'ejrst_articles',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_node_info().
 */
function ejrst_articles_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('An Article is a issue'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
