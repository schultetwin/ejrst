<?php
/**
 * @file
 * ejrst_articles.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ejrst_articles_taxonomy_default_vocabularies() {
  return array(
    'conceptual_area' => array(
      'name' => 'Conceptual Area',
      'machine_name' => 'conceptual_area',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'grade_level' => array(
      'name' => 'Grade Level',
      'machine_name' => 'grade_level',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'methodology' => array(
      'name' => 'Methodology',
      'machine_name' => 'methodology',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'science_topic' => array(
      'name' => 'Science Topic',
      'machine_name' => 'science_topic',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
