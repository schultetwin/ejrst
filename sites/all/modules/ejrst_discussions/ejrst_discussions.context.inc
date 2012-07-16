<?php
/**
 * @file
 * ejrst_discussions.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ejrst_discussions_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'articles';
  $context->description = 'Active on article pages.';
  $context->tag = 'EJRST';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-article_discussions-block' => array(
          'module' => 'views',
          'delta' => 'article_discussions-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active on article pages.');
  t('EJRST');
  $export['articles'] = $context;

  return $export;
}
