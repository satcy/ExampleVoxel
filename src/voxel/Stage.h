//
//  Stage.h
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//
#pragma once
#include "DisplayObjectContainer.h"
#include "ofMain.h"
using namespace std;
class Stage : public DisplayObjectContainer{
public:
    Stage(){
        span = 10;
        parent = NULL;
        bStage = true;
        pt.x = 0;
        pt.y = 0;
        pt.z = 0;
        rotationX = 0;
        rotationY = 0;
        rotationZ = 0;
    }
    ~Stage(){
    }
    void setup(int w, int h, int d);
    void updateStage();
    void drawStage();
protected:
private:
};