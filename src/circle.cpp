//
//  circle.cpp
//  mouse
//
//  Created by Ryota Nemoto on 2017/08/22.
//
//

#include "circle.hpp"

circle::circle(){
    m=5;//粒子の重さ
    M=10;//マウスの重さ
    G=0.0667408;//万有引力定数
    
    for(int i=0;i<NUM;i++){
        
        speed[i]=ofVec3f(0,0,0);
        
        vertice[i].set(ofRandom(-1*ofGetWidth()/2,ofGetWidth()/2),
                      ofRandom(-1*ofGetHeight()/2,ofGetHeight()/2),
                      0.0f);
        ofFloatColor color;
        color.setHsb(ofRandom(0.2),1,1);
        colors[i].set(color);
    }
    vert_buff_obj.setVertexData(vertice, NUM, GL_DYNAMIC_DRAW);
    vert_buff_obj.setColorData(colors,NUM,GL_DYNAMIC_DRAW);
    //vert_buff_obj.setNormalData(normals, NUM, GL_DYNAMIC_DRAW);//もしかしたら使うかも
}

void circle::update(){
    
    pos_m = ofVec3f(ofGetMouseX(),ofGetMouseY(),0);
    
    for(int i=0;i<NUM;i++){
        
        pos_cm[i]=pos_m-vertice[i];//粒子とマウスの距離
        F[i]=G*M*m/pos_cm[i].length()*pos_cm[i].length();//ばんゆういんりょくのけいさんしき
        pos_cm[i]= pos_cm[i].normalize();//pos_cmを単位ベクトルにする
        acc[i]=pos_cm[i]*F[i]/m;//加速度を求める
        speed[i] += acc[i];//速度を求める
        //速度を制御する↓
        if(speed[i].x>15){
            speed[i].x=15;
        }
        else if(speed[i].y>15){
            speed[i].y=15;
        }
        else if(speed[i].x<-15){
            speed[i].x=-15;
        }
        else if(speed[i].y<-15){
            speed[i].y=-15;
        }
        
        vertice[i] += speed[i];//円の動き
        r=ofNoise(ofGetElapsedTimef()/i*2)*255;
        g=ofNoise(ofGetElapsedTimef()/i*3)*255;
        b=ofNoise(ofGetElapsedTimef()/i*5)*255;
    }
    vert_buff_obj.updateVertexData(vertice, NUM);
}

void circle::draw(){
    //    for(int i=0; i<NUM; i++){
    //        ofSetColor(red[i],green[i],blue[i],127);
    //        ofDrawCircle(pos_c[i], 5);
    //    }
    glPointSize(1);
    glEnable(GL_POINT_SMOOTH);
    //cam.begin()
    //ofSetColor(51,212,221);
    vert_buff_obj.draw(GL_POINTS,0,NUM);
    
    //cam.end();
}


