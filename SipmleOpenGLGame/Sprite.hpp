//
//  Sprite.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-16.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <iostream>
#include <GL/glfw.h>

typedef struct {
    GLfloat x;
    GLfloat y;
} Vector2;

class Sprite
{
private:
    // attributes
    GLuint _textureBufferID;
    Vector2 _position;
    
public:
    // constructors
    Sprite(GLuint textureBufferID);

    // setters
    void setPosition(Vector2 newPosition);

    // getters
    Vector2 getPosition();
    
    // member function
    void render();
    void update();
};


#endif /* Sprite_hpp */
