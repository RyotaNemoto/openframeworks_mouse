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

        speed_[i]=ofVec3f(0,0,0);
        
        mVerts[i].set(ofRandom(-1*ofGetWidth()/2,ofGetWidth()/2),ofRandom(-1*ofGetHeight()/2,ofGetHeight()/2),0.0f);
            ofFloatColor color;
            color.setHsb(ofRandom(0.2),1,1);
            mColor[i].set(color);
        
        
    }
        mVbo.setVertexData(mVerts, NUM, GL_DYNAMIC_DRAW);
        mVbo.setColorData(mColor,NUM,GL_DYNAMIC_DRAW);
        //mVbo.setNormalData(mNormals, NUM, GL_DYNAMIC_DRAW);//もしかしたら使うかも
    
}
void circle::update(){
    
    pos_m = ofVec3f(ofGetMouseX(),ofGetMouseY(),0);

    for(int i=0;i<NUM;i++){
        
        pos_cm[i]=pos_m-mVerts[i];//粒子とマウスの距離
        F[i]=G*M*m/pos_cm[i].length()*pos_cm[i].length();//ばんゆういんりょくのけいさんしき
        pos_cm[i]= pos_cm[i].normalize();//pos_cmを単位ベクトルにする
        acc[i]=pos_cm[i]*F[i]/m;//加速度を求める
        speed_[i] += acc[i];//速度を求める
        //速度を制御する↓
        if(speed_[i].x>15){
            speed_[i].x=15;
            
        }
        else if(speed_[i].y>15){
            speed_[i].y=15;
            
        }
        else if(speed_[i].x<-15){
            speed_[i].x=-15;
            
        }
        else if(speed_[i].y<-15){
            speed_[i].y=-15;
        }
        
        
        mVerts[i] += speed_[i];//円の動き
        r=ofNoise(ofGetElapsedTimef()/i*2)*255;
        g=ofNoise(ofGetElapsedTimef()/i*3)*255;
        b=ofNoise(ofGetElapsedTimef()/i*5)*255;
        
    }

    mVbo.updateVertexData(mVerts, NUM);
    

    
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
    mVbo.draw(GL_POINTS,0,NUM);
    
    //cam.end();
}


