//
//  Sprite.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-16.
//  Copyright © 2016 apple. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(GLuint textureBufferID) : _textureBufferID(textureBufferID)
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
    glDrawArrays(GL_QUADS, 0, 4);
}

void Sprite::update()
{
}
