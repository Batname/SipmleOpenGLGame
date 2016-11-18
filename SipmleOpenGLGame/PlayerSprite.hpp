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
#include "Prefix.h"

class PlayerSprite : public Sprite
{
private:
    // arguments
    double f0;
    double f_move;
    BoundingBox _boundingBox;
    
    
public:
    PlayerSprite(GLuint textureBufferID, Vector2 position);
    
    // member functions
    void update();
    void setBoundingBox(BoundingBox boundingBox);
};

#endif /* PlayerSprite_hpp */
