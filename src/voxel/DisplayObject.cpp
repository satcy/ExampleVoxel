//
//  DisplayObject.cpp
//  runner
//
//  Created by satcy on 11/05/30.
//  Copyright 2011 Rhizomatiks. All rights reserved.
//

#include "DisplayObject.h"

void DisplayObject::resize(int w, int h, int d){
    deletePoint();
    int l = w*h*d;
    cp.reserve(l);
    trfm_cp.reserve(l);
    for ( int i = 0; i<l; i++ ) {
        cp.push_back(new ColorPoint( i%w, int(i/w)%h, int(i/(w*h)) ));
        trfm_cp.push_back(new ColorPoint( i%w, int(i/w)%h, int(i/(w*h)) ));
    }
    width = w;
    height = h;
    depth = d;
}

void DisplayObject::setColor(int r, int g, int b){
    int l = cp.size();
    for ( int i = 0; i<l; i++ ) {
        cp[i]->color.r = r;
        cp[i]->color.g = g;
        cp[i]->color.b = b;
    }
}

void DisplayObject::offset(int x, int y, int z){
    int l = cp.size();
    for ( int i = 0; i<l; i++ ) {
        cp[i]->pt.x += x;
        cp[i]->pt.y += y;
        cp[i]->pt.z += z;
        trfm_cp[i]->pt.x += x;
        trfm_cp[i]->pt.y += y;
        trfm_cp[i]->pt.z += z;
    }
}

void DisplayObject::update(){
    if ( !stage ) return;
    if ( !parent ) return;
    int l = cp.size();
    ofPoint t_pt;
    DisplayObjectBase * d;
    float off_x = (parent == stage ) ? 0 : pt.x;
    float off_y = (parent == stage ) ? 0 : pt.y;
    float off_z = (parent == stage ) ? 0 : pt.z;
    float off_rota_x = rotationX;
    float off_rota_y = rotationY;
    float off_rota_z = rotationZ;
    d = parent;
    
    while ( d != stage ) {
        if ( d->parent != stage ) {
            off_x += d->pt.x;
            off_y += d->pt.y;
            off_z += d->pt.z;
        }
        off_rota_x += d->rotationX;
        off_rota_y += d->rotationY;
        off_rota_z += d->rotationZ;
        d = d->parent;
    }
    
    //cout << off_y << endl;
    for ( int i=0; i<l; i++ ){
        t_pt = cp[i]->pt;
        ofVec3f vec;
        vec.x = t_pt.x + off_x;
        vec.y = t_pt.y + off_y;
        vec.z = t_pt.z + off_z;
        vec.rotate(off_rota_x, off_rota_y, off_rota_z);
        trfm_cp[i]->pt.x = vec.x - off_x;
        trfm_cp[i]->pt.y = vec.y - off_y;
        trfm_cp[i]->pt.z = vec.z - off_z;
        trfm_cp[i]->color.r = cp[i]->color.r;
        trfm_cp[i]->color.g = cp[i]->color.g;
        trfm_cp[i]->color.b = cp[i]->color.b;
    }
}

void DisplayObject::draw(){
    if ( !stage ) return;
    if ( !parent ) return;
    float off_x = pt.x;
    float off_y = pt.y;
    float off_z = pt.z;
    DisplayObjectBase * d = parent;
    while ( d != stage ) {
        off_x += d->pt.x;
        off_y += d->pt.y;
        off_z += d->pt.z;
        d = d->parent;
    }
    int l = trfm_cp.size();
    int stage_size = stage->cp.size();
    float nx = 0;
    float ny = 0;
    float nz = 0;
    //cout << l << endl;
    //cout << "" << endl;
    //float sqrt_3 = sqrt(3);
    float r,g,b;
    for ( int i=0; i<l; i++ ){
        nx = (off_x + trfm_cp[i]->pt.x);
        ny = (off_y + trfm_cp[i]->pt.y);
        nz = (off_z + trfm_cp[i]->pt.z);
        if ( smoothing ) {
            float lx = fabs(nx - floor(nx));
            float ly = fabs(ny - floor(ny));
            float lz = fabs(nz - floor(nz));
            //cout << "--" << endl;
            //cout << nx << " " << lx << endl;
            //cout << "-" << endl;
            for ( int j=0; j<8; j++ ) {
                float sx = float(j%2);
                float sy = float(int(j/2)%2);
                float sz = float(int(j/4)%2);
                
                if ( floor(nx) + sx < 0 || floor(nx) + sx > stage->width-1 || floor(ny) + sy < 0 || floor(ny) + sy > stage->height-1 || floor(nz) + sz < 0 || floor(nz) + sz > stage->depth-1 ) {
                    
                } else {
                    int index =  floor((floor(nx) + sx) + (floor(ny) + sy) * stage->width + (floor(nz) + sz) * stage->width * stage->height);
                    float dx = fabs(sx - lx);
                    float dy = fabs(sy - ly);
                    float dz = fabs(sz - lz);
                    //float dd = sqrt(dx*dx + dy*dy + dz*dz);
                    //float ratio = (sqrt_3 - dd)/sqrt_3;
                    float ratio = ((1-dx) * (1-dy) * (1-dz));
                    //cout << dx << " " << dz << " " << ratio << endl;
                    r = stage->cp[index]->color.r;
                    g = stage->cp[index]->color.g;
                    b = stage->cp[index]->color.b;
                    if ( index >= 0 && index < stage_size ) {
                        if ( blendMode == 0 ) {
                            r += trfm_cp[i]->color.r*ratio;
                            g += trfm_cp[i]->color.g*ratio;
                            b += trfm_cp[i]->color.b*ratio;
                        } else if ( blendMode == 1 ) {
                            r += trfm_cp[i]->color.r*ratio;
                            g += trfm_cp[i]->color.g*ratio;
                            b += trfm_cp[i]->color.b*ratio;
                        }
                    }
                    if ( r > 255 ) r = 255;
                    if ( g > 255 ) g = 255;
                    if ( b > 255 ) b = 255;
                    stage->cp[index]->color.r = r;
                    stage->cp[index]->color.g = g;
                    stage->cp[index]->color.b = b;
                }
            }
        } else {
            if ( floor(nx) < 0 || floor(nx) > stage->width-1 || floor(ny) < 0 || floor(ny) > stage->height-1 || floor(nz) < 0 || floor(nz) > stage->depth-1 ) {
                
            } else {
                int index =  floor((floor(nx)) + (floor(ny)) * stage->width + (floor(nz)) * stage->width * stage->height);
                r = stage->cp[index]->color.r;
                g = stage->cp[index]->color.g;
                b = stage->cp[index]->color.b;
                if ( index >= 0 && index < stage_size ) {
                    if ( blendMode == 0 ) {
                        r = trfm_cp[i]->color.r;
                        g = trfm_cp[i]->color.g;
                        b = trfm_cp[i]->color.b;
                    } else if ( blendMode == 1 ) {
                        r += trfm_cp[i]->color.r;
                        g += trfm_cp[i]->color.g;
                        b += trfm_cp[i]->color.b;
                    }
                }
                if ( r > 255 ) r = 255;
                if ( g > 255 ) g = 255;
                if ( b > 255 ) b = 255;
                stage->cp[index]->color.r = r;
                stage->cp[index]->color.g = g;
                stage->cp[index]->color.b = b;
            }
        }
        
    }
}

void DisplayObject::deletePoint(){
    if ( !cp.empty() ) {
        for ( int i = cp.size()-1; i>=0; i-- ) {
            delete cp[i];
        }
        cp.clear();
    }
    if ( !trfm_cp.empty() ) {
        for ( int i = trfm_cp.size()-1; i>=0; i-- ) {
            delete trfm_cp[i];
        }
        trfm_cp.clear();
    }
}
