
//
//  xml_settings.cpp
//  emptyExample
//
//  Created by Mark van de Korput on 16-04-25.
//
//

#include "xml_settings.h"
#include "ofxXmlSettings.h"

using namespace of2030;


XmlSettings* XmlSettings::singleton = NULL;

XmlSettings* XmlSettings::instance(){
    if (!singleton){   // Only allow one instance of class to be generated.
        singleton = new XmlSettings();
    }
    return singleton;
}

XmlSettings::XmlSettings() : path("settings.xml"), loaded(false){
  if(singleton == NULL){
    singleton = this;
  } else {
    ofLogWarning() << "Non-singleton instance of XmlSettings constructed";
  }
};

void XmlSettings::load(bool reload){
    if(loaded && !reload)
      return;

    ofxXmlSettings xml;
    xml.loadFile(path);
    osc_port = xml.getValue("of2030:osc_port", 2030);
    client_id = xml.getValue("of2030:client_id", 1);
    screen_width = xml.getValue("of2030:screen_width", 768);
    screen_height = xml.getValue("of2030:screen_height", 576);
    loaded = true;
}

void XmlSettings::save(){
    ofxXmlSettings xml;
    xml.setValue("of2030:osc_port", osc_port);
    xml.setValue("of2030:client_id", client_id);
    xml.setValue("of2030:screen_width", screen_width);
    xml.setValue("of2030:screen_height", screen_height);
    xml.saveFile(path);
}
