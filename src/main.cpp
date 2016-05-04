#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLWindowSettings settings;
	settings.setGLVersion(3,2);
	ofCreateWindow(settings);
	// ofSetupOpenGL(1024,768, OF_WINDOW); // OF_FULLSCREEN
	ofRunApp( new ofApp());
}
