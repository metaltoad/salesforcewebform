<?php
// $Id$

// available fields in SalesForce
$salesforcewebform_available_fields = array(	
	//Special Field to block Processing
	0 => '--Do Not Map to SalesForce--',

	// names
	'Title' => 'Title',
	'Salutation' => 'Salutation',
	'FirstName' => 'First Name',
	'LastName' => 'Last Name',
	'Company' => 'Company',
		
	// email addresses and website
	'Email' => 'Email',
	'HasOptedOutOfEmail' => 'E-Mail Opt Out',
	'Website' => 'Website',
	
	// lead  info for SalesForce
	'AccountName' => 'Account Name',
	'Description' => 'Description',
	'LeadSource' => 'Lead Source',
	'ReferredBy' => 'Referred By',
	
	// phone numbers
	'Phone' => 'Phone', 
	'MobilePhone' => 'Mobile',
	'Fax' => 'Fax',
	'DoNotCall' => 'Do Not Call',
	'HasOptedOutOfFax' => 'Fax Opt Out',
	
	// adddresses
	'City' => 'City',
	'Country' => 'Country',
	'PostalCode' => 'Zip',
	'State' => 'State/Province',
	'Street' => 'Address',

	// extra
	'Birthdate' => 'Birthdate',
	'Description' => 'Description',
	'Industry' => 'Industry',
	'Rating' => 'Rating',
	'AnnualRevenue' => 'Annual Revenue',
	'NumberOfEmployees' => 'Employees',
	'Campaign' => 'Campaign_ID',
	
	//Special SID Field to map for editing
	'WebformSID__c' => 'Webform SID Key',
	
);

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