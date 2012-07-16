<?php
/**
 * @file
 * ejrst_discussions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ejrst_discussions_user_default_permissions() {
  $permissions = array();

  // Exported permission: create discussion content.
  $permissions['create discussion content'] = array(
    'name' => 'create discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create field_discussion_article.
  $permissions['create field_discussion_article'] = array(
    'name' => 'create field_discussion_article',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete any discussion content.
  $permissions['delete any discussion content'] = array(
    'name' => 'delete any discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own discussion content.
  $permissions['delete own discussion content'] = array(
    'name' => 'delete own discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any discussion content.
  $permissions['edit any discussion content'] = array(
    'name' => 'edit any discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit field_discussion_article.
  $permissions['edit field_discussion_article'] = array(
    'name' => 'edit field_discussion_article',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own discussion content.
  $permissions['edit own discussion content'] = array(
    'name' => 'edit own discussion content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own field_discussion_article.
  $permissions['edit own field_discussion_article'] = array(
    'name' => 'edit own field_discussion_article',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_discussion_article.
  $permissions['view field_discussion_article'] = array(
    'name' => 'view field_discussion_article',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_discussion_article.
  $permissions['view own field_discussion_article'] = array(
    'name' => 'view own field_discussion_article',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
