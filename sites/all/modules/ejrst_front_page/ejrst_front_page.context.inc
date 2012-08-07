<?php
/**
 * @file
 * ejrst_front_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ejrst_front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = 'Frontpage Context';
  $context->tag = 'EJRST';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-8fd674bfe17656a5934f87304facf69b' => array(
          'module' => 'views',
          'delta' => '8fd674bfe17656a5934f87304facf69b',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-featured_articles-block' => array(
          'module' => 'views',
          'delta' => 'featured_articles-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('EJRST');
  t('Frontpage Context');
  $export['frontpage'] = $context;

  return $export;
}
