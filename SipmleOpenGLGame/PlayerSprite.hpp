//
//  PlayerSprite.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-17.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef PlayerSprite_hpp
#define PlayerSprite_hpp

#include "Sprite.hpp"

#include <Gl/glfw.h>

class PlayerSprite : public Sprite
{
private:
    double f0;
    double f_move;
    
    
public:
    PlayerSprite(GLuint textureBufferID, Vector2 position);
    
    // member functions
    void update();
};

#endif /* PlayerSprite_hpp */
