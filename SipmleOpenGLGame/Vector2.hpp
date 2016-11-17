//
//  Vector2.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef Vector2_hpp
#define Vector2_hpp

#include <GL/glfw.h>

typedef struct {
    GLfloat x;
    GLfloat y;
} Vector2;

Vector2 makeVector2(GLfloat x, GLfloat y);
Vector2 addVector2(Vector2 first, Vector2 second);

#endif /* Vector2_hpp */
