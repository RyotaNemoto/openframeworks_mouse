#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    circle = *new Circle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

void ofApp::update(){
    circle.update();
}

void ofApp::draw(){
    circle.draw();
}

void ofApp::keyPressed(int key){
    if(key == 'e'){
    circle.explode();
    }
    else if(key == 'a'){
        circle.frash();
            //circle.update();
        }
    else if(key == 'r'){
        circle.reset();
    }
}


