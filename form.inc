<?php
/**
 * Took this directly from example 4 of the form examples in Examples.
 *
 */
function rlh_datalayer_test_form($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form with required fields'),
  );

  $form['name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
    // Make the fieldset collapsible.
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Make these fields required.
  $form['name']['first'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#required' => TRUE,
  );
  $form['name']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#required' => TRUE,
  );

  $form['date'] = array(
    '#type' => 'textfield',
    '#title' => t('Date'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}

/**
 * Validation function for form_example_tutorial_7().
 *
 * @ingroup form_example
 */
function rlh_datalayer_test_form_validate($form, &$form_state) {
  $date = $form_state['values']['date'];
  if ($date && (! preg_match('/\d{4}-\d{1,2}-\d{1,2}/', $date)) ) {
    form_set_error('date', t('Format must be YYYY-MM-DD'));
  }
}

/**
 * Submit function for form_example_tutorial_7().
 *
 * Adds a submit handler/function to our form to send a successful
 * completion message to the screen.
 *
 * @ingroup form_example
 */
function rlh_datalayer_test_form_submit($form, &$form_state) {
  drupal_set_message(t('The form has been submitted. name="@first @last", date=@date',
    array(
      '@first' => $form_state['values']['first'],
      '@last' => $form_state['values']['last'],
      '@date' => $form_state['values']['date'],
    )
  ));
  datalayer_add(array(
    'formFirstName' => $form_state['values']['first'],
    'formLastName' => $form_state['values']['last'],
    'formDate' => $form_state['values']['date'],
  ));

}
