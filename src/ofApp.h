#pragma once

#include "ofMain.h"
#include "circle.hpp"
#define NUM 1000

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
    
    circle c;
    
private:
    ofVec2f pos_c[NUM];//円の位置ベクトル
    ofVec2f pos_m;//マウスの位置ベクトル
    ofVec2f pos_cm[NUM];//合成
    ofVec2f acc[NUM];//加速度
    ofVec2f speed_[NUM];//速度
    
    //BNN_BeyondIntaraction P106から
    float loc_x[NUM];
    float loc_y[NUM];
    float radius[NUM];
    int red[NUM];
    int green[NUM];
    int blue[NUM];
    bool mouse_pressed;
    float m;//円の重さ
    float M;//マウスの重さ
    float F[NUM];//力
    float G;//万有引力定数
    
    ofEasyCam cam;
    
    
};
