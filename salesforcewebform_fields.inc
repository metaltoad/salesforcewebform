<?php

function salesforcewebform_load_custom_fields($loadtype) {
  $custom_fields = variable_get('salesforcewebform_custom_fields', array());
  $return_fields = array();
  if ( is_array($custom_fields) ) {
    if ($loadtype == "webform") {
      foreach ($custom_fields as $cfkey => $cfvalue) {
        $cfkey = strtolower($cfkey);
        $return_fields[$cfkey] = $cfvalue;
      }
    }
    else {
      $return_fields = $custom_fields;
    }
    return $return_fields ;
  }
  else return array();
}


/*
 * Obtain the available fields in SalesForce
 * @param string $form_sfobject_typecode Salesforce Object Type
 * @return $fields Array of fields available
 */
function salesforcewebform_available_fields($form_sfobject_typecode) {
   $fields = array(    
    //Special Field to block Processing
    0 => '--Do Not Map to SalesForce--',
    );

  //Define Implementation for hook_salesforcewebform_fields
  $fields = array_merge($fields, module_invoke_all('salesforcewebform_fields', $form_sfobject_typecode));

  return $fields;
}

// required fields in SalesForce
function salesforcewebform_required_fields($form_sfobject_typecode) {

  //Define Implementation for hook_salesforcewebform_fields
  $fields = module_invoke_all('salesforcewebform_required_fields', $form_sfobject_typecode);

  return $fields;
}