//
//  circle.cpp
//  mouse
//
//  Created by Ryota Nemoto on 2017/08/22.
//
//

#include "circle.hpp"

circle::circle(){
    
    
    m=5;
    M=10;
    G=0.0667408;
    
    for(int i=0;i<NUM;i++){

        speed_[i]=ofVec3f(0,0,0);
        /*
        red[i]=ofRandom(255);
        green[i]=ofRandom(255);
        blue[i]=ofRandom(255);
        */
       
        mVerts[i].set(ofRandom(-1*ofGetWidth()/2,ofGetWidth()/2),ofRandom(-1*ofGetHeight()/2,ofGetHeight()/2),0.0f);
            //ofFloatColor color;
            //color.setHsb(ofRandom(0.2),1,1);
            //mColor[i].set(color);
        
        //}
    }
        mVbo.setVertexData(mVerts, NUM, GL_DYNAMIC_DRAW);
        mVbo.setColorData(mColor,NUM,GL_DYNAMIC_DRAW);
        //mVbo.setNormalData(mNormals, NUM, GL_DYNAMIC_DRAW);
        

        
    

    
}
void circle::update(){
    
    pos_m = ofVec3f(ofGetMouseX(),ofGetMouseY(),0);

    for(int i=0;i<NUM;i++){
        
        pos_cm[i]=pos_m-mVerts[i];
        F[i]=G*M*m/pos_cm[i].length()*pos_cm[i].length();
        pos_cm[i]= pos_cm[i].normalize();
        acc[i]=pos_cm[i]*F[i]/m;
        speed_[i] += acc[i];
        //cout<<acc[i]<<endl;
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
        
        
        mVerts[i] += speed_[i];
        //cout<<speed_[i]<<endl;
        //mVerts[i] += ofRandom(1);
        //cout << mVerts[i] << endl;
      
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


