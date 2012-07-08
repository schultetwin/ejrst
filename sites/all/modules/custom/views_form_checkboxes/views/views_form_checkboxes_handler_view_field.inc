<?php

class views_form_checkboxes_handler_view_field extends views_handler_field_field {
  function render_items($values) {
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  function form_element_name() {
    // Make sure this value is unique for all the view fields
    return $this->options['id'];
  }

  function form_element_row_id($row_id) {
    // You could use values from $this->view->result[$row_id]
    // to provide complex row ids.
    return $row_id;
  }

  function views_form(&$form, &$form_state) {
    if (empty($this->view->result)) {
      return;
    }

    $form['#action'] = $this->view->get_url();
    $field_name = $this->form_element_name();
    $form[$field_name] = array(
      '#tree' => TRUE,
    );
    foreach ($this->view->result as $row_id => $row) {
      $form_element_row_id = $this->form_element_row_id($row_id);
      $div = $field_name . '-' . $form_element_row_id . '-content-access';
      $row->{'field_' . $this->field}['0']['rendered']['#printed'] = FALSE;
      $form[$field_name][$form_element_row_id]['checkbox_form'] = array(
        '#type' => 'checkbox',
        '#title' => drupal_render($row->{'field_' . $this->field}['0']['rendered']),
        '#default_value' => $row->{'field_' . $this->field}['0']['raw']['value'],
        '#prefix' => '<div id="' . $div . '">',
        '#suffix' => '</div>',
        '#ajax' => array(
          'callback' => 'views_form_checkboxes_ajax_callback',
          'wrapper' => $div,
        ),
      );
      $form[$field_name][$form_element_row_id]['entity_type'] = array('#type' => 'value', '#value' => $row->{$this->aliases['entity_type']});
      $form[$field_name][$form_element_row_id]['entity_id'] = array('#type' => 'value', '#value' => $row->{$this->field_alias});
      $form[$field_name][$form_element_row_id]['field_name'] = array('#type' => 'value', '#value' => $this->field_info['field_name']);
    }
  }

  function views_form_submit($form, &$form_state) {
    $field_name = $this->form_element_name();
    foreach ($form_state['values'][$field_name] as $value) {
      $entities = entity_load($value['entity_type'], array($value['entity_id']));
      $entity = array_pop($entities);
      $entity_wrapper = entity_metadata_wrapper($value['entity_type'], $entity);
      $entity_wrapper->{$value['field_name']}->set($value['checkbox_form']);
      $entity_wrapper->save();
    }
  }
}
