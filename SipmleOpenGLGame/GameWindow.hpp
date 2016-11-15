//
//  GameWindow.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-15.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef GameWindow_hpp
#define GameWindow_hpp

#include <GL/glfw.h>

class GameWindow
{
private:
    
    // attributes
    bool _running;
public:
    // constructor
    GameWindow(bool running);
    
    // setters
    void setRuning(bool newRunning);
    
    // getters
    bool getRunning();
    
    // member functions
    void render();
    void update();
};

#endif /* GameWindow_hpp */