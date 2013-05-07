//
//  plane.h
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#pragma once
#include "DisplayObject.h"
#include "ofMain.h"

class Plane : public DisplayObject{
public:
    Plane(){}
    ~Plane(){}
    void setColor(int r, int g, int b){
        int l = cp.size();
        for ( int i = 0; i<l; i++ ) {
            //cp[i]->color.r = int(ofRandom(0,255));
            //cp[i]->color.g = int(ofRandom(0,255));
            //cp[i]->color.b = int(ofRandom(0,255));
            cp[i]->color.r = r;
            cp[i]->color.g = g;
            cp[i]->color.b = b;
        }
    }
protected:
    
private:
    
    
};