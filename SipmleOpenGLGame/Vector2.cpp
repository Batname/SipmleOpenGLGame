//
//  Vector2.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#include "Vector2.hpp"

Vector2 makeVector2(GLfloat x, GLfloat y)
{
    Vector2 newVector;
    newVector.x = x;
    newVector.y = y;
    return newVector;
}

Vector2 addVector2(Vector2 first, Vector2 second)
{
    Vector2 newVector;
    newVector.x = first.x + second.y;
    newVector.y = first.y + second.y;
    return newVector;
}
