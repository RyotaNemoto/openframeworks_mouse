#pragma once

#include "ofMain.h"
#include "circle.hpp"
#define NUM 11

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    Circle circle;
};
