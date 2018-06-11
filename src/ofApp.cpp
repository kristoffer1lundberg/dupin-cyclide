#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    aP.set("A", 171.87, 0.0, 255.0);
    bP.set("B", 162.89, 0.0, 255.0);
    cP.set("C", 0, -255, 255);
    dP.set("D", 93.24, 0.0, 255.0);
    
    gui = new ofxDatGui(0, 0);
    gui->setWidth(500);
    
    aSlider = gui->addSlider(aP);
    aSlider->onSliderEvent(this, &ofApp::onSliderEvent);
    
    bSlider = gui->addSlider(bP);
    bSlider->onSliderEvent(this, &ofApp::onSliderEvent);
    
    cSlider = gui->addSlider(cP);
    cSlider->onSliderEvent(this, &ofApp::onSliderEvent);
    
    dSlider = gui->addSlider(dP);
    dSlider->onSliderEvent(this, &ofApp::onSliderEvent);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    glEnable(GL_POINT_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glPointSize(4.0f);
    
    cam.begin();
    ofSetColor(255, 255, 255);
    glBegin(GL_POINTS);
    
    float a = aP.get();
    float b = bP.get();
    float c = cP.get();
    c = sqrt( pow(a, 2) - pow(b, 2) );
    cP.set(c);
    float d = dP.get();
    
    for (float u = 0.0; u < TWO_PI; u += 0.03) {
        for (float v = 0.0; v < TWO_PI; v += 0.03) {
            
            float x = d * (c - a * cos(v)*cos(u)) + b * b * cos(u);
            x = x / (a - c * cos(u) * cos(v));
            
            float y = b * sin(u) * (a - d * cos(v));
            y = y / (a - c * cos(u) * cos(v));
            
            float z = b * sin(v) * (c * cos(u) - d);
            z = z / (a - c * cos(u) * cos(v));
            
            glVertex3f(x, y, z);
        }
    }
    
    glEnd();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::onSliderEvent(ofxDatGuiSliderEvent e) {
    cout << "changed" << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
