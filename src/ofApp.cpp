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
