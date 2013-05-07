//
//  Stage.cpp
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//
#include "Stage.h"
void Stage::setup(int w, int h, int d){
    resize(w, h, d);
}

void Stage::updateStage(){
    int l = cp.size();
    for ( int i=0; i<l; i++ ){
        cp[i]->color.r = 0.;
        cp[i]->color.g = 0.;
        cp[i]->color.b = 0.;
    }
    update();
}

void Stage::drawStage(){
    draw();
    ofFill();
    glEnable(GL_DEPTH_TEST);
    ofEnableAlphaBlending();
    int l = cp.size();
    ofPoint offset( -span*width*0.5, -span*height*0.5, -span*depth*0.5 );
    for ( int i=0; i<l; i++ ){
        int a = 255;
        if ( cp[i]->color.r == 0 && cp[i]->color.g == 0 && cp[i]->color.b == 0 ) a = 50;
        ofPushMatrix();
        ofTranslate(cp[i]->pt.x * span + offset.x, cp[i]->pt.y * span + offset.y, cp[i]->pt.z * span + offset.z);
        ofSetColor(int(cp[i]->color.r), int(cp[i]->color.g), int(cp[i]->color.b), a);
        ofBox(0, 0, 0, span/4);
        ofPopMatrix();
    }
    glDisable(GL_DEPTH_TEST);
    ofFill();
}
