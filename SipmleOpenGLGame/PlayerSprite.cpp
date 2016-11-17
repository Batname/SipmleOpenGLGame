//
//  PlayerSprite.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#include "PlayerSprite.hpp"

PlayerSprite::PlayerSprite(GLuint textureBufferID, Vector2 position) :
    Sprite(textureBufferID, position), f0(0.0f), f_move(5.5f)
{
    
}

void PlayerSprite::update()
{
    
    if(glfwGetKey(GLFW_KEY_UP) && _position.y <= _boundingBox.top) {
        _position = addVector2(_position, makeVector2(f0, f_move));
    }
    
    if(glfwGetKey(GLFW_KEY_DOWN) && _position.y >= _boundingBox.bottom) {
        _position = addVector2(_position, makeVector2(f0, -f_move));
    }
    
    if(glfwGetKey(GLFW_KEY_LEFT) && _position.x >= _boundingBox.left) {
        _position = addVector2(_position, makeVector2(-f_move, f0));
    }
    
    if(glfwGetKey(GLFW_KEY_RIGHT) && _position.x <= _boundingBox.right) {
        _position = addVector2(_position, makeVector2(f_move, f0));
    }
}

void PlayerSprite::setBoundingBox(BoundingBox boundingBox)
{
    _boundingBox = boundingBox;
}
