//for oF_0073
#include "testApp.h"
#include "Stage.h"
#include "WireCube.h"

ofEasyCam camera;
Stage * stage;
WireCube * wc;
    
void testApp::setup(){
    ofBackground(50, 50, 50);
    ofSetFrameRate(30);
    
    camera.setDistance(200);
    
    stage = new Stage();
    //ボクセル領域を、11*11*11に設定
    stage->setup(11, 11, 11);
    
    wc = new WireCube();
    //ライン表示のCube
    stage->addChild(wc);
    wc->setup();
    wc->pt.x = 5;
    wc->pt.y = 5;
    wc->pt.z = 5;
    
}

void testApp::update(){
    //Cubeの回転
    wc->rotationX += 5;
    wc->rotationY += 4;
    wc->rotationZ += 3;
    
    stage->updateStage();
}

void testApp::draw(){
    camera.begin();
    ofPushMatrix();
    stage->drawStage();
    ofPopMatrix();
    
    camera.end();
}
