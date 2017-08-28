//
//  circle.hpp
//  mouse
//
//  Created by Ryota Nemoto on 2017/08/22.


#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>
#include "ofMain.h"
#define PARTICL_NUM 20000

class Circle{
    
public:
    Circle();
    void setup();
    void update();
    void draw();
    void explode();
    void flash();
    float alpha;//透明度
    void reset();
    bool color_e;
    bool color_a;
    bool color_r;
    
private:
    ofTrueTypeFont font;
    ofTrueTypeFont font_e;
    ofTrueTypeFont font_a;
    //ofVec2f pos_c[PARTICL_NUM];//円の位置ベクトル
    ofVec3f pos_mouse;//マウスの位置ベクトル
    ofVec3f pos_cm[PARTICL_NUM];//合成
    ofVec3f acc[PARTICL_NUM];//加速度
    ofVec3f speed[PARTICL_NUM];//速度
    
    // 色
    float r, g, b;
    //float alpha;//透明度
    float m;//円の重さ
    float M;//マウスの重さ
    float F[PARTICL_NUM];//力
    float G;//万有引力定数
    float font_size_e;
    
    ofEasyCam cam; // A super simple camera for interacting with objects in 3D space.
    
    ofVbo vert_buff_obj; // Vbo = Vertex Buffer Objects
    ofVec3f vertice[PARTICL_NUM]; // 頂点の数
    ofFloatColor colors[PARTICL_NUM]; // 色の数
    ofVec3f normals[PARTICL_NUM]; // 3次元ベクトル用データ構造
};


#endif /* circle_hpp */
