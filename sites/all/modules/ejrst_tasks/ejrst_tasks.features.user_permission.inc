<?php
/**
 * @file
 * ejrst_tasks.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ejrst_tasks_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete any tasks content.
  $permissions['delete any tasks content'] = array(
    'name' => 'delete any tasks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own tasks content.
  $permissions['delete own tasks content'] = array(
    'name' => 'delete own tasks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any tasks content.
  $permissions['edit any tasks content'] = array(
    'name' => 'edit any tasks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own tasks content.
  $permissions['edit own tasks content'] = array(
    'name' => 'edit own tasks content',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
