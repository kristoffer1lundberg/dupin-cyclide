#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

	public:
        ofxDatGui* gui;
        ofxDatGuiSlider* aSlider;
        ofxDatGuiSlider* bSlider;
        ofxDatGuiSlider* cSlider;
        ofxDatGuiSlider* dSlider;
    
        ofParameter<float> aP;
        ofParameter<float> bP;
        ofParameter<float> cP;
        ofParameter<float> dP;
    
        ofEasyCam cam;
    
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
    
        void onSliderEvent(ofxDatGuiSliderEvent e);
		
};
