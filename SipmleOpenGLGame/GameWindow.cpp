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
    {{-Square_Size/2, -Square_Size/2, 0.0f},{0.0f, 0.0f}},
    {{Square_Size/2, -Square_Size/2, 0.0f},	{1.0f, 0.0f}},
    {{Square_Size/2, Square_Size/2, 0.0f},	{1.0f,1.0f}},
    {{-Square_Size/2, Square_Size/2, 0.0f}, {0.0f, 1.0f}}
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
    _rockTextureBufferID = loadAndBufferImage("rock.tga");
    
    _ballsArray = new std::vector<Ball *>;
    _ballsArray->reserve(20);
    
    _rocksArray = new std::vector<Rock *>;
    _rocksArray->reserve(20);
    
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
    glDeleteTextures(1, &_textureBufferID);
    glDeleteTextures(1, &_ballTectureBufferID);
    glDeleteTextures(1, &_rockTextureBufferID);
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
    renderBalls();
    renderRocks();
 
    glfwSwapBuffers();
}

void GameWindow::update()
{
    clearByCollision();
    clearBalls();
    clearRocks();
    
    static int updates;
    if (updates >= 60){
        addRock();
        updates = 0;
    }
    ++updates;
    
    _playerRocket->update();
    updateBalls();
    updateRocks();
}

bool GameWindow::checkForCollision(Sprite *a, Sprite *b)
{
    return !(
             a->getPosition().x + Square_Size/2 <= b->getPosition().x - Square_Size/2 ||
             a->getPosition().x - Square_Size/2 >= b->getPosition().x + Square_Size/2 ||
             a->getPosition().y + Square_Size/2 <= b->getPosition().y - Square_Size/2 ||
             a->getPosition().y - Square_Size/2 >= b->getPosition().y + Square_Size/2
             );
}

void GameWindow::clearByCollision()
{
    for (std::vector<Rock *>::iterator spriteIteratorRock = _rocksArray->begin(); spriteIteratorRock != _rocksArray->end(); spriteIteratorRock++) {
        if (checkForCollision(*spriteIteratorRock, _playerRocket)){
            _deleteRocksArray->push_back(spriteIteratorRock);
        }
        
        for (std::vector<Ball *>::iterator spriteIteratorBall = _ballsArray->begin(); spriteIteratorBall != _ballsArray->end(); spriteIteratorBall++) {
            if (checkForCollision(*spriteIteratorRock, *spriteIteratorBall)){
                _deleteRocksArray->push_back(spriteIteratorRock);
                _deleteBallsArray->push_back(spriteIteratorBall);
            }
        }
    }
}

void GameWindow::renderBalls()
{
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        (* spriteIterator)->render();
    }
}

void GameWindow::renderRocks()
{
    for (std::vector<Rock *>::iterator spriteIterator = _rocksArray->begin(); spriteIterator != _rocksArray->end(); spriteIterator++) {
        (* spriteIterator)->render();
    }
}

void GameWindow::addBall()
{
    Ball * ball = new Ball(_ballTectureBufferID, makeVector2(_playerRocket->getPosition().x + Square_Size/2, _playerRocket->getPosition().y));
    ball->setVelocity(makeVector2(5.0f, 0.0f));
    _ballsArray->push_back(ball);
}

void GameWindow::addRock()
{
    int locationY = rand() % (int)_height;
    Rock *rock = new Rock(_rockTextureBufferID, makeVector2(_width + Square_Size/2, locationY));
    rock->setVelocity(makeVector2(-5,0));
    rock->setRotationVelocity(1);
    _rocksArray->push_back(rock);
}

void GameWindow::updateBalls()
{
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        (* spriteIterator)->update();
    }
}

void GameWindow::updateRocks()
{
    for (std::vector<Rock *>::iterator spriteIterator = _rocksArray->begin(); spriteIterator != _rocksArray->end(); spriteIterator++) {
        (* spriteIterator)->update();
    }
}

void GameWindow::clearBalls()
{
    _deleteBallsArray = new std::vector<std::vector<Ball *>::iterator>;
    for (std::vector<Ball *>::iterator spriteIterator = _ballsArray->begin(); spriteIterator != _ballsArray->end(); spriteIterator++) {
        if(((*spriteIterator)->getPosition()).x > _width + Square_Size) {
            _deleteBallsArray->push_back(spriteIterator);
        }
    }
    
    for(std::vector<std::vector<Ball *>::iterator>::iterator deleteIterator = _deleteBallsArray->begin(); deleteIterator != _deleteBallsArray->end(); deleteIterator++) {
        if((**deleteIterator)->getVelocity().x > 0) {
            _ballsArray->erase(*deleteIterator);
        }
    }
}

void GameWindow::clearRocks()
{
    _deleteRocksArray = new std::vector<std::vector<Rock *>::iterator>;
    for (std::vector<Rock *>::iterator spriteIterator = _rocksArray->begin(); spriteIterator != _rocksArray->end(); spriteIterator++) {
        if(((*spriteIterator)->getPosition()).x > _width + Square_Size) {
            _deleteRocksArray->push_back(spriteIterator);
        }
    }
    
    for(std::vector<std::vector<Rock *>::iterator>::iterator deleteIterator = _deleteRocksArray->begin(); deleteIterator != _deleteRocksArray->end(); deleteIterator++) {
        _rocksArray->erase(*deleteIterator);
        if((**deleteIterator)->getVelocity().x > 0) {
            _rocksArray->erase(*deleteIterator);
        }
    }
}

void GameWindow::mouseButtonPressed(int button, int action)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT  && action == GLFW_PRESS) {
        addBall();
        std::cout << _ballsArray->size() <<std::endl;
    }
}
