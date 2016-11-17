//
//  Sprite.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-16.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <GL/glfw.h>

#include "Vector2.hpp"

class Sprite
{
private:
    // attributes
    GLuint _textureBufferID;
    Vector2 _velocity;
    
protected:
    Vector2 _position;
    
public:
    // constructors
    Sprite(GLuint textureBufferID, Vector2 position);

    // setters
    void setPosition(Vector2 newPosition);
    void setVelocity(Vector2 newVector);

    // getters
    Vector2 getPosition();
    Vector2 getVelocity();
    
    // member function
    void render();
    virtual void update();
};


#endif /* Sprite_hpp */
