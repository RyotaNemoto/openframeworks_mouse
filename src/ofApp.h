#pragma once

#include "ofMain.h"
#include "circle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    Circle circle;
};
