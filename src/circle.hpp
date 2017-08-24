//
//  circle.hpp
//  mouse
//
//  Created by Ryota Nemoto on 2017/08/22.


#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>
#include "ofMain.h"
#define NUM 10000


class circle{
    
public:
    circle();
    void setup();
    void update();
    void draw();
    
private:
    //ofVec2f pos_c[NUM];//円の位置ベクトル
    ofVec3f pos_m;//マウスの位置ベクトル
    ofVec3f pos_cm[NUM];//合成
    ofVec3f acc[NUM];//加速度
    ofVec3f speed_[NUM];//速度
    
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
    float r,g,b;
    ofEasyCam cam;
    
    ofVbo mVbo;
    ofVec3f mVerts[NUM];
    ofFloatColor mColor[NUM];
    ofVec3f mNormals[NUM];
};


#endif /* circle_hpp */
