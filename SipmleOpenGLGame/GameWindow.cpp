//
//  GameWindow.cpp
//  SipmleOpenGLGame
//
//  Created by apple on 2016-11-15.
//  Copyright © 2016 apple. All rights reserved.
//

#include "GameWindow.hpp"

typedef struct {
    GLfloat positionCoordinates[3];
} VertexData;

#define Square_Size 100

VertexData vertices[] = {
    {0.0f, 0.0f, 0.0f},
    {Square_Size, 0.0f, 0.0f},
    {Square_Size, Square_Size, 0.0f},
    {0.0f, Square_Size, 0.0f}
};

GameWindow::GameWindow(bool running) :
    _running(running),
    _height(800),
    _width(800*16/9),
    _vertexBufferID(0)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0.0f, 0.0f, _width, _height);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, _width, 0, _height);
    glMatrixMode(GL_MODELVIEW);
    
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *) __offsetof(VertexData, positionCoordinates));
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
    glDrawArrays(GL_QUADS, 0, 4);
 
    glfwSwapBuffers();
}

void GameWindow::update()
{
}
