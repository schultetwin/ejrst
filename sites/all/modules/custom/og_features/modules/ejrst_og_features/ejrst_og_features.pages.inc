<?php

/**
 * Page calback for ejrst og features
 */
function ejrst_og_features_page($node, $type) {
  $group = og_get_group('node', $node->nid);
  $output = '';
  $view_name = '';
  switch ($type) {
    case 'discussion':
      $view_name = 'group_discussions';
      break;
    case 'blog':
      $view_name = 'group_blog';
      break;
    case 'note':
      $view_name = 'group_notes';
      break;
    case 'task':
      $view_name = 'group_tasks';
      break;
    case 'wiki':
      $view_name = 'group_wiki';
      break;
    case 'news':
      $view_name = 'group_news';
      break;
  }
  $output .= views_embed_view($view_name, 'default', $group->gid);
  return $output;
}