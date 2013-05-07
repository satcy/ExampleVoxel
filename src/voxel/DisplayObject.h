//
//  DisplayObject.h
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//
#pragma once
#include <vector>
#include "ofTypes.h"
#include "ColorPoint.h"
#include "DisplayObjectBase.h"

using namespace std;

class DisplayObject : public DisplayObjectBase {    
public:
    DisplayObject(){}
    ~DisplayObject(){
        deletePoint();
        parent = NULL;
        stage = NULL;
    }
    void resize(int w, int h, int d);
    void setColor(int r, int g, int b);
    void update();
    void draw();
    void offset(int x, int y, int z);
    void deletePoint();
};