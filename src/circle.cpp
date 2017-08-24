//
//  circle.cpp
//  mouse
//
//  Created by Ryota Nemoto on 2017/08/22.
//
//

#include "circle.hpp"

Circle::Circle(){
    m = 5;//粒子の重さ
    M = 10;//マウスの重さ
    G = 0.0667408;//万有引力定数
    
    // 初期データの作成
    for(int i = 0; i < PARTICL_NUM; i++){
        
        speed[i] = ofVec3f(0, 0, 0);
        
        vertice[i].set(ofRandom(-1 * ofGetWidth() / 2, ofGetWidth() / 2),
                       ofRandom(-1 * ofGetHeight() / 2, ofGetHeight() / 2),
                       0.0f);
        
    }
    
    vert_buff_obj.setVertexData(vertice, PARTICL_NUM, GL_DYNAMIC_DRAW);
//    vert_buff_obj.setColorData(colors, PARTICL_NUM, GL_DYNAMIC_DRAW);
    //vert_buff_obj.setNormalData(normals, PARTICL_NUM, GL_DYNAMIC_DRAW);//もしかしたら使うかも
}

void Circle::update(){
    
    // 現在のマウス位置を取得
    pos_mouse = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0);
    
    // 各頂点の位置を万有引力の計算式を用いて計算
    for(int i = 0; i < PARTICL_NUM; i++) {
        
        pos_cm[i] = pos_mouse - vertice[i]; // 粒子とマウスの距離
        F[i] = G * M * m / pos_cm[i].length() * pos_cm[i].length(); // 万有引力の計算式
        
        pos_cm[i] = pos_cm[i].normalize(); // pos_cmを単位ベクトルにする
        acc[i] = pos_cm[i] * F[i] / m; // 加速度を求める
        speed[i] += acc[i]; // 速度を求める
        
        // 速度を制御する↓
        // TODO: ここはifではなくてelse if?
        if (speed[i].x > 15) {
            speed[i].x = 15;
        }
        else if (speed[i].y > 15) {
            speed[i].y = 15;
        }
        else if (speed[i].x < -15) {
            speed[i].x = -15;
        }
        else if (speed[i].y < -15) {
            speed[i].y = -15;
        }

        //円の動き
        vertice[i] += speed[i];
        
        float elapsedTime = ofGetElapsedTimef();
        r = ofNoise(elapsedTime / 10);
        g = ofNoise(elapsedTime / 80);
        b = ofNoise(elapsedTime / 50);
        ofFloatColor color;
        color.set(r, g, b);
        colors[i].set(color);

    }
    
    vert_buff_obj.updateVertexData(vertice, PARTICL_NUM);
    vert_buff_obj.setColorData(colors, PARTICL_NUM, GL_DYNAMIC_DRAW);
}

void Circle::draw(){

    
    glPointSize(1);
    glEnable(GL_POINT_SMOOTH);
    
    vert_buff_obj.draw(GL_POINTS, 0 ,PARTICL_NUM);
    
}


