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

class Circle{
    
public:
    Circle();
    void setup();
    void update();
    void draw();
    
private:
    //ofVec2f pos_c[NUM];//円の位置ベクトル
    ofVec3f pos_m;//マウスの位置ベクトル
    ofVec3f pos_cm[NUM];//合成
    ofVec3f acc[NUM];//加速度
    ofVec3f speed[NUM];//速度
    
    // 色
    float r, g, b;
    
    float m;//円の重さ
    float M;//マウスの重さ
    float F[NUM];//力
    float G;//万有引力定数
    
    ofEasyCam cam; // A super simple camera for interacting with objects in 3D space.
    
    ofVbo vert_buff_obj; // Vbo = Vertex Buffer Objects
    ofVec3f vertice[NUM]; // 頂点の数
    ofFloatColor colors[NUM]; // 色の数
    ofVec3f normals[NUM]; // 3次元ベクトル用データ構造
};


#endif /* circle_hpp */
