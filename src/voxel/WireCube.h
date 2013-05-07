//
//  WireCube.h
//  runner
//
//  Created by satcy on 11/05/31.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//
#pragma once
#include <vector>
#include "DisplayObjectContainer.h"
#include "Plane.h"
#include "ofMain.h"

class WireCube : public DisplayObjectContainer{
public:
    WireCube(){
        blendMode = 0;
        smoothing = true;
    }
    ~WireCube(){
        int l = pls.size();
        Plane * pl;
        for ( int i=0; i<l; i++ ){
            pl = pls[i];
            removeChild(pl);
            delete pl;
        }
        pls.clear();
        deletePoint();
    }
    void setup(){
        int l = 12;
        pls.reserve(l);
        Plane * pl;
        float w = 7;
        float xx = 3;
        int sizes[36] = { w, 1, 1, w, 1, 1, 1, w, 1, 1, w, 1,
        w, 1, 1, w, 1, 1, 1, w, 1, 1, w, 1,
        1, 1, w, 1, 1, w, 1, 1, w, 1, 1, w };
        float pts[36] = { -xx, -xx, xx, -xx, xx, xx, -xx, -xx, xx, xx, -xx, xx,
        -xx, -xx, -xx, -xx, xx, -xx, -xx, -xx, -xx, xx, -xx, -xx,
        -xx, -xx, -xx, xx, -xx, -xx, xx, xx, -xx, -xx, xx, -xx };
        for ( int i=0; i<l; i++ ){
            pl = new Plane();
            pl->resize(sizes[i*3+0], sizes[i*3+1], sizes[i*3+2]);
            pl->setColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
            pl->blendMode = blendMode;
            pl->smoothing = smoothing;
            pl->pt.x = pts[i*3+0];
            pl->pt.y = pts[i*3+1];
            pl->pt.z = pts[i*3+2];
            addChild(pl);
            pls.push_back(pl);
        }
    }
protected:
    
private:
    vector<Plane *> pls;
    
};