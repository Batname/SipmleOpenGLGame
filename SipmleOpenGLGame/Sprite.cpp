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


void Sprite::render()
{
    glBindTexture(GL_TEXTURE_2D, _textureBufferID);
    glLoadIdentity();
    glTranslatef(_position.x, _position.y, 0);
    glDrawArrays(GL_QUADS, 0, 4);
}

void Sprite::update()
{
}
