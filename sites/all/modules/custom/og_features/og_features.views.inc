<?php

/**
 * Implements hook_views_plugins().
 */
function og_features_views_plugins() {
  return array(
    'argument validator' => array(
      'og_features_nid_as_gid' => array(
        'title' => t('Node ID as GID + Group Feature'),
        'handler' => 'og_feature_argument_validate_nid_as_gid',
        'uses options' => TRUE,
      ),
    ),
  );
}
