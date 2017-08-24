#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    mouse_pressed=false;
    c=*new circle();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

void ofApp::update(){
    c.update();
}


void ofApp::draw(){
    c.draw();
}

void ofApp::keyPressed(int key){
    
}

void ofApp::keyReleased(int key){
    
}


void ofApp::mouseMoved(int x, int y ){
    
}


void ofApp::mouseDragged(int x, int y, int button){
    
    
}


void ofApp::mousePressed(int x, int y, int button){
    //     mouse_pressed=true;
}


void ofApp::mouseReleased(int x, int y, int button){
    //    mouse_pressed=false;
    //    for(int i=0; i<NUM; i++){
    //        speed_[i]=ofVec2f(ofRandom(-5,5),ofRandom(-5,5));
    //    }
}


void ofApp::mouseEntered(int x, int y){
    
}


void ofApp::mouseExited(int x, int y){
    
}


void ofApp::windowResized(int w, int h){
    
}


void ofApp::gotMessage(ofMessage msg){
    
}


void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
