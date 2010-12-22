<?php

// $Id$

module_load_include('inc', 'fedora_repository', 'plugins/ModsFormBuilder');
class UofMBook extends ModsFormBuilder {
  function createCollectionPolicy($form_values, &$dom, &$rootElement) {
    parent::createCollectionPolicy($form_values, &$dom, &$rootElement);
    if (is_dir($form_values['ingest-file-location'])) { 
      $cproot = $rootElement->getElementsByTagName('collection_policy');
      if ($cproot != NULL && $cproot->length > 0) { 
        $cproot=$cproot->item(0);
        $staging = $cproot->getElementsByTagName('staging_area');
        if ($staging != NULL && $staging->length > 0) { 
          $staging->item(0)->nodeValue= $form_values['ingest-file-location'];
        } else  {
          $staging = $dom->createElement('staging_area',$form_values['ingest-file-location']);
          $cproot->appendChild($staging);
        }
      }
    }
  }
}