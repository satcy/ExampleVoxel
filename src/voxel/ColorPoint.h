//
//  colorPoint.h
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//
#pragma once
#include "ofTypes.h"

class ColorPoint{
public:
    ofPoint pt;
    ofColor color;
    ColorPoint(){
        pt.x = pt.y = pt.x = 0;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 0;
    }
    ColorPoint(float x, float y, float z){
        pt.x = x;
        pt.y = y;
        pt.z = z;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 255;
    }
    ColorPoint(float x, float y, float z, float r, float g, float b){
        pt.x = x;
        pt.y = y;
        pt.z = z;
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = 255;
    }
    ~ColorPoint(){
    }
protected:

private:
};
