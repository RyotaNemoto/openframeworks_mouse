#pragma once

#include "ofMain.h"
#include "circle.hpp"
#define NUM 1000

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    circle c;
};
