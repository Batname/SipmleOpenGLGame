//
//  Ball.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-19.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include "Prefix.h"
#include "Sprite.hpp"

class Ball : public Sprite
{
public:
    Ball(GLuint textureBufferID, Vector2 position);
};

#endif /* Ball_hpp */
