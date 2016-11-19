//
//  Sprite.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-16.
//  Copyright © 2016 apple. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(GLuint textureBufferID, Vector2 position) :
    _textureBufferID(textureBufferID),
    _position(position)
{

}


void Sprite::setPosition(Vector2 newPosition)
{
    _position = newPosition;
}


Vector2 Sprite::getPosition()
{
    return _position;
}

void Sprite::setVelocity(Vector2 newVector)
{
    _velocity = newVector;
}

Vector2 Sprite::getVelocity()
{
    return _velocity;
}

void Sprite::setRotation(GLfloat rotation)
{
    _rotation = rotation;
}

GLfloat Sprite::getRotation()
{
    return _rotation;
}

void Sprite::setRotationVelocity(GLfloat rotationVelocity)
{
    _rotationVelocity = rotationVelocity;
}

GLfloat Sprite::getRotationVelocity()
{
    return _rotationVelocity;
}

void Sprite::render()
{
    glBindTexture(GL_TEXTURE_2D, _textureBufferID);
    glLoadIdentity();
    glTranslatef(_position.x, _position.y, 0);
    glRotatef(_rotation, 0, 0, 1.0f);
    glDrawArrays(GL_QUADS, 0, 4);
}

void Sprite::update()
{
    _position = addVector2(_position, _velocity);
    _rotation += _rotationVelocity;
}
