#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofLogToFile("log.txt", true);

  // settings and config
  xml_settings = of2030::XmlSettings::instance();
  xml_settings->load();

  // set app-wide log-leel based on configuration
  map<string, ofLogLevel> level_map = {
    {"verbose", OF_LOG_VERBOSE},
    {"notice", OF_LOG_NOTICE},
    {"warning", OF_LOG_WARNING},
    {"error", OF_LOG_ERROR},
    {"fatal", OF_LOG_FATAL_ERROR},
    {"silent", OF_LOG_SILENT}
    {"", OF_LOG_NOTICE}
  };
  ofSetLogLevel(level_map[xml_settings->log_level]);

  client_info = of2030::ClientInfo::instance();
  client_info->id = xml_settings->client_id;

  // incoming data
  interface = of2030::Interface::instance();
  osc_receiver.configure(xml_settings->osc_port, interface);

  // visual playback system
  player = of2030::Player::instance();
  renderer = of2030::Renderer::instance();

  renderer->setup();
  player->start();
  interface_player_bridge.start();
  osc_receiver.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
  osc_receiver.update();
  player->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  renderer->draw();
}

//--------------------------------------------------------------
void ofApp::exit(ofEventArgs &args){
  osc_receiver.destroy();
  interface_player_bridge.stop();

  delete renderer;
  renderer = NULL;

  delete player;
  player = NULL;

  delete interface;
  interface = NULL;

  delete client_info;
  client_info = NULL;

  delete xml_settings;
  xml_settings = NULL;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
