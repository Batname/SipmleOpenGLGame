//
//  Rock.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-19.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef Rock_hpp
#define Rock_hpp

#include "Prefix.h"
#include "Sprite.hpp"

class Rock : public Sprite
{
public:
    Rock(GLuint textureBufferID, Vector2 position);
};

#endif /* Rock_hpp */
