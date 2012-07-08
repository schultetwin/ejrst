<?php
/**
 * @file
 * ejrst_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ejrst_base_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '1',
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '2',
  );

  return $roles;
}
