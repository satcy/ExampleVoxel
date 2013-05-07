//
//  DisplayObjectBase.h
//  runner
//
//  Created by satcy on 11/06/01.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//
#pragma once
#include <vector>
#include "ColorPoint.h"
using namespace std;

class DisplayObjectBase : public ColorPoint {    
public:
    DisplayObjectBase(){
        rotationX = 0;
        rotationY = 0;
        rotationZ = 0;
        width = 1;
        height = 1;
        depth = 1;
        span = 0;
        blendMode = 0;
        bStage = 0;
        smoothing = false;
    }
    virtual ~DisplayObjectBase() {}
    DisplayObjectBase * parent;
    DisplayObjectBase * stage;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void offset(int x, int y, int z) = 0;
    float rotationX;
    float rotationY;
    float rotationZ;
    float scaleX;
    float scaleY;
    float scaleZ;
    int width;
    int height;
    int depth;
    float span;
    int blendMode;
    bool smoothing;
    bool bStage;
    vector<ColorPoint*> cp;
    vector<ColorPoint*> trfm_cp;
};
