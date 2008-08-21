<?php
// $Id$

// available fields in SalesForce
$salesforcewebform_available_fields = array(	
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
	'LeadSource' => 'Lead Source Description',
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
	'Lead_source' => 'Lead Source',
	'Industry' => 'Industry',
	'Rating' => 'Rating',
	'AnnualRevenue' => 'Annual Revenue',
	'NumberOfEmployees' => 'Employees',
	'Campaign' => 'Campaign_ID',
	
	//Special SID Field to map for editing
	'WebformSID__c' => 'Webform SID Key',
	
);

function salesforcewebform_load_custom_fields () {
	$custom_fields = variable_get('salesforcewebform_custom_fields', null);
	if ( is_array($custom_fields) ) return $custom_fields ;
	else return array();
}