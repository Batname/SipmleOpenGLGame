//
//  GameWindow.hpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-15.
//  Copyright © 2016 apple. All rights reserved.
//

#ifndef GameWindow_hpp
#define GameWindow_hpp

#include "PlayerSprite.hpp"
#include "Ball.hpp"
#include "Prefix.h"

class GameWindow
{
private:
    
    // attributes
    bool _running;
    GLfloat _height;
    GLfloat _width;
    GLuint _vertexBufferID;
    GLuint _textureBufferID;
    GLuint _ballTectureBufferID;
    PlayerSprite * _playerRocket;
    std::vector<Ball *> * _ballsArray;
    
    // member functions
    GLuint loadAndBufferImage(const char *filename);
    void setupGL();
    void appendBall();
    void updateBalls();
    
public:
    // constructor
    GameWindow(bool running);
    
    // destructor
    ~GameWindow();
    
    // setters
    void setRuning(bool newRunning);
    
    // getters
    bool getRunning();
    
    // member functions
    void render();
    void update();
    void mouseButtonPressed(int button, int action);
};

#endif /* GameWindow_hpp */
