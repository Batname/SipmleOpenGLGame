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
    _textureBufferID = loadAndBufferImage("rotated_rocket.tga");
    _ballTectureBufferID = loadAndBufferImage("ball2.tga");
    
    _ballsArray = new std::vector<Ball *>;
    _ballsArray->reserve(20);
    
    _playerRocket = new PlayerSprite(_textureBufferID, makeVector2(_height/2, 300));
    _playerRocket->setBoundingBox(makeBoundingBox(_height, 0, 0, _width));
    
}

GameWindow::~GameWindow()
{
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        delete (* spriteIterator);
    }
    delete _ballsArray;
    delete _playerRocket;
    
    glDeleteBuffers(1, &_vertexBufferID);
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
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageData.Width, imageData.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.Data);
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
    
    _playerRocket->render();
    
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        (* spriteIterator)->render();
    }
 
    glfwSwapBuffers();
}

void GameWindow::appendBall()
{
    Ball * ball = new Ball(_ballTectureBufferID, makeVector2(_playerRocket->getPosition().x + Square_Size/2, _playerRocket->getPosition().y));
    ball->setVelocity(makeVector2(5.0f, 0.0f));
    
    _ballsArray->push_back(ball);
}

void GameWindow::updateBalls()
{
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        (* spriteIterator)->update();
    }
}

void GameWindow::clearBalls()
{
    std::vector<std::vector<Ball *>::iterator> deleteArray;
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        if(((*spriteIterator)->getPosition()).x > _width + Square_Size) {
            deleteArray.push_back(spriteIterator);
        }
    }
    
    for(std::vector<std::vector<Ball *>::iterator>::iterator deleteIterator = deleteArray.begin(); deleteIterator != deleteArray.end(); deleteIterator++) {
        _ballsArray->erase(*deleteIterator);
    }
}

void GameWindow::update()
{
    clearBalls();
    _playerRocket->update();
    updateBalls();
}

void GameWindow::mouseButtonPressed(int button, int action)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT  && action == GLFW_PRESS) {
        appendBall();
        std::cout << _ballsArray->size() <<std::endl;
    }
}
