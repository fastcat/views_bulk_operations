<?php
// $Id$

/**
 * Implementation of hook_rules_action_info().
 */
function views_bulk_operations_rules_action_info() {
  $actions = array();
  foreach (module_invoke_all('views_bulk_operations_object_info') as $type => $info) {
    $actions['views_bulk_operations_rules_action_' . $type] = array(
      'label' => t('Use !type object to execute a VBO programmatically', array('!type' => $type)),
      'arguments' => array(
        'object' => array(
          'type' => $type,
          'label' => t('Object'),
          'description' => t('The chosen object will be loaded as the <code>$object</code> variable, available below.'),
        ),
      ),
      'module' => 'Views Bulk Operations',
      'eval input' => array(),
      'base' => 'views_bulk_operations_rules_action',
    );
  }
  return $actions;
}

function views_bulk_operations_rules_action($object, $settings, $element, &$state) {
  views_bulk_operations_action($object, $settings);
  return array('object' => $object);
}

function views_bulk_operations_rules_action_form($settings, &$form, &$form_state) {
  $form += views_bulk_operations_action_form($settings);
}

function views_bulk_operations_rules_action_validate($form, &$form_state) {
  views_bulk_operations_action_validate($form, $form_state);
}

function views_bulk_operations_rules_action_submit(&$settings, $form, &$form_state) {
  $submit = views_bulk_operations_action_submit($form, $form_state);
  $settings = array_merge($settings, $submit);
}

