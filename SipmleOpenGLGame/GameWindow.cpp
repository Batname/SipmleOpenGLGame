//
//  GameWindow.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-15.
//  Copyright © 2016 apple. All rights reserved.
//

#include "GameWindow.hpp"

GameWindow::GameWindow(bool running) : _running(running), _height(800), _width(800*16/9)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0.0f, 0.0f, _width, _height);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, _width, 0, _height);
    glMatrixMode(GL_MODELVIEW);
}

void GameWindow::setRuning(bool newRunning)
{
    _running = newRunning;
}

bool GameWindow::getRunning()
{
    return _running;
}

void GameWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(  0.0f,   0.0f);
    glVertex2d(100.0f,   0.0f);
    glVertex2d(100.0f, 100.0f);
    glVertex2d(  0.0f, 100.0f);
    glEnd();
    glfwSwapBuffers();
}

void GameWindow::update()
{
}
