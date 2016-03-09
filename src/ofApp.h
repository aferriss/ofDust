#pragma once

#include "ofMain.h"
#include "ofxVideoRecorder.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void pickRandSpots(int spotCount);
        void exit();
    
        int w, h;
        ofImage img;
        bool save;
        ofFbo fbo, screen;
        ofPixels pix;
        vector<int> spots;
        int numSpots;
//        int yPos;
        ofShader shader;
        string folder;
        int inc;
    int linePos, xPos, yPos, xInc, yInc;
    ofxVideoRecorder recorder;
};
