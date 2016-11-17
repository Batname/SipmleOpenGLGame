//
//  BoundingBox.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef BoundingBox_hpp
#define BoundingBox_hpp

typedef struct{
    int top;
    int bottom;
    int left;
    int right;
} BoundingBox;

BoundingBox makeBoundingBox(int top, int bottom, int left, int right);

#endif /* BoundingBox_hpp */
