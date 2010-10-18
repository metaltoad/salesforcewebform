<?php
// $Id$

function salesforcewebform_load_custom_fields ($loadtype) {
	$custom_fields = variable_get('salesforcewebform_custom_fields', array());
	$return_fields = array();
	if ( is_array($custom_fields) ) {
    if($loadtype == "webform") {
      foreach( $custom_fields as $cfkey=>$cfvalue) {
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


// available fields in SalesForce
function salesforcewebform_available_fields() {
   $fields = array(    
    //Special Field to block Processing
    0 => '--Do Not Map to SalesForce--',
    );

  //Define Implementation for hook_salesforcewebform_fields
  $fields = array_merge($fields, module_invoke_all('salesforcewebform_fields'));

  return $fields;
}
