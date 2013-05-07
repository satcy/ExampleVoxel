//
//  DisplayObjectContainer.h
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//

#pragma once
#include <list>
#include "DisplayObject.h"
#include "Stage.h"
using namespace std;


class DisplayObjectContainer : public DisplayObject{
public:
    DisplayObjectContainer(){}
    ~DisplayObjectContainer(){
        list<DisplayObjectBase *>::iterator it = lists.begin();
        while( it != lists.end() ){
            DisplayObjectBase * o = *it;
            delete o;
            ++it;
        }
        lists.clear();
    }
    void update(){
        list<DisplayObjectBase *>::iterator it = lists.begin();
        while( it != lists.end() ){
            DisplayObjectBase * o = *it;
            o->update();
            ++it;
        }
    }
    void draw(){
        list<DisplayObjectBase *>::iterator it = lists.begin();
        while( it != lists.end() ){
            DisplayObjectBase * o = *it;
            o->draw();
            ++it;
        }
    }
    void addChild(DisplayObjectBase *o){
        o->parent = this;
        if ( bStage ) o->stage = this;
        else if ( stage ) o->stage = stage;
        lists.push_back(o);
    }
    void removeChild(DisplayObjectBase *o){
        o->parent = NULL;
        o->stage = NULL;
        lists.remove(o);
    }
    bool hasContent(DisplayObjectBase *obj){
        bool b = false;
        list<DisplayObjectBase *>::iterator it = lists.begin();
        while( it != lists.end() ){
            DisplayObjectBase * o = *it;
            if ( o == obj ) b = true;
            ++it;
        }
        return b;
    }
protected:
    list<DisplayObjectBase *> lists;
};