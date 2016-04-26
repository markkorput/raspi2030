#pragma once

#include "ofMain.h"
#include "xml_settings.h"
#include "client_info.h"
#include "interface.hpp"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void exit(ofEventArgs &args);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		of2030::XmlSettings *xml_settings;
		of2030::ClientInfo *client_info;
		of2030::Interface *interface;

};
