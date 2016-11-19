//
//  Sprite.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-16.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "Prefix.h"

#define Square_Size 100

class Sprite
{
private:
    // attributes
    GLuint _textureBufferID;
    Vector2 _velocity;
    GLfloat _rotation;
    
protected:
    Vector2 _position;
    
public:
    // constructors
    Sprite(GLuint textureBufferID, Vector2 position);

    // setters
    void setPosition(Vector2 newPosition);
    void setVelocity(Vector2 newVector);
    void setRotation(GLfloat rotation);

    // getters
    Vector2 getPosition();
    Vector2 getVelocity();
    GLfloat getRotation();
    
    // member function
    void render();
    virtual void update();
};


#endif /* Sprite_hpp */
