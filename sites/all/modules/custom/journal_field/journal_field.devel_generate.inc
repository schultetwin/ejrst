<?php

/**
 * Implements hook_devel_generate().
 */
function journal_field_devel_generate($object, $field, $instance, $bundle) {
  switch ($field['type']) {
    case 'journal_field':
      $return = array(
        'volume' => round(rand(0, 10)),
        'issue' => round(rand(0,20)),
        'special_issue' => round(rand(0,1)),
      );
      if ($return['special_issue']) {
        $return['special_issue_title'] = devel_generate_word(mt_rand(2, 30));
      }
      break;
  }
  return $return;
}