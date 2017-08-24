#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    circle = *new Circle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

void ofApp::update(){
    circle.update();
}

void ofApp::draw(){
    circle.draw();
}
