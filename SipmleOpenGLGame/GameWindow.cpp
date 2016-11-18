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
    GLfloat textureCoordinates[2];
} VertexData;

VertexData vertices[] = {
    {{0.0f, 0.0f, 0.0f},{0.0f, 0.0f}},
    {{Square_Size, 0.0f, 0.0f},{1.0f, 0.0f}},
    {{Square_Size, Square_Size, 0.0f},{1.0f, 1.0f}},
    {{0.0f, Square_Size, 0.0f},{0.0f, 1.0f}}
};

GameWindow::GameWindow(bool running) :
    _running(running),
    _height(800),
    _width(800*16/9),
    _vertexBufferID(0)
{
    setupGL();
    _textureBufferID = loadAndBufferImage("rocket_1.tga");
    
    renderArray = new std::vector<Sprite *>;
    
    PlayerSprite * roket = new PlayerSprite(_textureBufferID, makeVector2(500, 500));
    roket->setBoundingBox(makeBoundingBox(_height, 0, 0, _width));
    renderArray->push_back(roket);
    
    Sprite * otherRocket = new Sprite(_textureBufferID, makeVector2(700, 400));
    otherRocket->setVelocity(makeVector2(1.0f, 1.0f));
    renderArray->push_back(otherRocket);
}

GameWindow::~GameWindow()
{
    for (std::vector<Sprite *>::iterator spriteIterator = renderArray->begin(); spriteIterator != renderArray->end(); spriteIterator++) {
        delete (* spriteIterator);
    }
    delete renderArray;
}

void GameWindow::setupGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0.0f, 0.0f, _width, _height);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, _width, 0, _height);
    glMatrixMode(GL_MODELVIEW);
    
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *) __offsetof(VertexData, positionCoordinates));
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *) __offsetof(VertexData, textureCoordinates));
}

GLuint GameWindow::loadAndBufferImage(const char *filename)
{
    GLFWimage imageData;
    glfwReadImage(filename, &imageData, NULL);
    
    GLuint textureBufferID;
    glGenTextures(1, &textureBufferID);
    glBindTexture(GL_TEXTURE_2D, textureBufferID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageData.Width, imageData.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData.Data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glfwFreeImage(&imageData);
    
    return textureBufferID;
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
    
    for (std::vector<Sprite *>::iterator spriteIterator = renderArray->begin(); spriteIterator != renderArray->end(); spriteIterator++) {
        (* spriteIterator)->render();
    }
 
    glfwSwapBuffers();
}

void GameWindow::update()
{
    for (std::vector<Sprite *>::iterator spriteIterator = renderArray->begin(); spriteIterator != renderArray->end(); spriteIterator++) {
        (* spriteIterator)->update();
    }
}
