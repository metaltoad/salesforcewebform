<?php
// $Id$

// available fields in SalesForce
function salesforcewebform_available_fields() {
  return array(	
    //Special Field to block Processing
    0 => '--Do Not Map to SalesForce--',
    
    //Common fields for all form types
    'Common Fields' => array(
      'FirstName' => 'First Name',
      'LastName' => 'Last Name*',
      'Website' => 'Website',
      'Fax' => 'Fax',
      'Email' => 'Email',
      'RecordTypeID' => 'Record Type',
      'LeadSource' => 'Lead Source',      
      'WebformSID__c' => 'Webform SID Key',
    ),

    // Lead
    'Lead Fields' => array(
      'Phone' => 'Phone',
      'OwnerId' => 'Owner ID',
      'MobilePhone' => 'Mobile',
      'City' => 'City',
      'PostalCode' => 'Postal Code',
      'Country' => 'Country',    
      'Company' => 'Company',
    ),
    
    //Contact settings
    'Contact Fields' => array(
      'HomePhone' => 'Home Phone',
      'MobilePhone' => 'Mobile',
      'MailingCity' => 'City',
      'MailingPostalCode' => 'Postal Code',
      'MailingCountry' => 'Country',
      'ContactOwner' => 'Contact Owner',
    ),
    
    //Account settings
    'Account Fields' => array(
      'AccountOwner' => 'Account Owner',
      'Name' => 'Name*',
      'Phone' => 'Phone',
      'OwnerId' => 'Owner ID',
      'BillingCity' => 'City',
      'BillingPostalCode' => 'Postal Code',
      'BillingCountry' => 'Country',
    ),
    
    //Person Account fields
    'Person Account Fields' => array(
      'PersonEmail' => 'Email',
      'PersonHomePhone' => 'Home Phone',
      'PersonMobilePhone' => 'Mobile',
      'PersonMailingCity' => 'City',
      'PersonPostalCode' => 'Postal Code',
      'PersonMailingCountry' => 'Country',
    ),
  );
}

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