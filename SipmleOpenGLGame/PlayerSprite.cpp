//
//  PlayerSprite.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#include "PlayerSprite.hpp"

PlayerSprite::PlayerSprite(GLuint textureBufferID, Vector2 position) :
    Sprite(textureBufferID, position), f0(0.0f), f_move(1.5f)
{
    
}

void PlayerSprite::update()
{
    
    if (glfwGetKey(GLFW_KEY_UP)) {
        _position = addVector2(_position, makeVector2(f0, f_move));
    } else if (glfwGetKey(GLFW_KEY_DOWN)) {
        _position = addVector2(_position, makeVector2(f0, -f_move));
    } else if (glfwGetKey(GLFW_KEY_LEFT)) {
        _position = addVector2(_position, makeVector2(-f_move, f0));
    } else if (glfwGetKey(GLFW_KEY_RIGHT)) {
        _position = addVector2(_position, makeVector2(f_move, f0));
    }
}
