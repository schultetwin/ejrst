<?php
/**
 * @file
 * ejrst_journal.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function ejrst_journal_field_default_fields() {
  $fields = array();

  // Exported field: 'comment-comment_node_journal-comment_body'.
  $fields['comment-comment_node_journal-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_journal',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-journal-field_journal_issue_cover'.
  $fields['node-journal-field_journal_issue_cover'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_journal_issue_cover',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'journal',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'journal_cover_large',
          ),
          'type' => 'image',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'journal_cover_small',
          ),
          'type' => 'image',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_journal_issue_cover',
      'label' => 'Issue Cover',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'file_directory' => 'journal/covers',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '-1',
      ),
    ),
  );

  // Exported field: 'node-journal-field_journal_link'.
  $fields['node-journal-field_journal_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_journal_link',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'ejrst_custom',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'wiley_journal_link',
    ),
    'field_instance' => array(
      'bundle' => 'journal',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'ejrst_custom',
          'settings' => array(),
          'type' => 'wiley_journal_link',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'ejrst_custom',
          'settings' => array(),
          'type' => 'wiley_journal_link',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_journal_link',
      'label' => 'Journal Link',
      'required' => 0,
      'settings' => array(
        'field_instance' => 'field_journal_publication',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'ejrst_custom',
        'settings' => array(),
        'type' => 'wiley_journal_link',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-journal-field_journal_publication'.
  $fields['node-journal-field_journal_publication'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_journal_publication',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'journal_field',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'journal_field',
    ),
    'field_instance' => array(
      'bundle' => 'journal',
      'default_value' => array(
        0 => array(
          'volume' => '',
          'issue' => '',
          'special_issue' => 0,
          'special_issue_title' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'journal_field',
          'settings' => array(),
          'type' => 'journal_field_default_formatter',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_journal_publication',
      'label' => 'Publication',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'journal_field',
        'settings' => array(),
        'type' => 'journal_field_widget',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-journal-field_journal_publication_date'.
  $fields['node-journal-field_journal_publication_date'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_journal_publication_date',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '1',
        'cache_enabled' => 1,
        'granularity' => array(
          'day' => 0,
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datestamp',
    ),
    'field_instance' => array(
      'bundle' => 'journal',
      'deleted' => '0',
      'description' => 'Publication date (ex. "December 2009")',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'long',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
          ),
          'type' => 'date_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_journal_publication_date',
      'label' => 'Publication Date',
      'required' => 0,
      'settings' => array(
        'default_value' => 'blank',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'custom',
          'input_format_custom' => 'F Y',
          'label_position' => 'above',
          'text_parts' => array(
            0 => 'year',
          ),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_select',
        'weight' => '-3',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comment');
  t('Issue Cover');
  t('Journal Link');
  t('Publication');
  t('Publication Date');
  t('Publication date (ex. "December 2009")');

  return $fields;
}
