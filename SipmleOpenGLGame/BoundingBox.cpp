//
//  BoundingBox.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#include "BoundingBox.hpp"

BoundingBox makeBoundingBox(int top, int bottom, int left, int right)
{
    BoundingBox boundingBox;
    boundingBox.top = top;
    boundingBox.bottom = bottom;
    boundingBox.left = left;
    boundingBox.right = right;
    return boundingBox;
}
