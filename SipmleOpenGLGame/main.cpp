#include "GameWindow.hpp"

#include <GL/glfw.h>

GameWindow * gameWindow;

int main(int argc, const char * argv[]) {

    glfwInit();
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    glfwOpenWindow(800*16/9, 800, 8, 8, 8, 8, 0, 0, GLFW_WINDOW);
    glfwSetWindowTitle("OpenGL title");
    
    gameWindow = new GameWindow(true);
    
    while(gameWindow->getRunning()) {
        gameWindow->render();
        gameWindow->update();
        gameWindow->setRuning(glfwGetWindowParam(GLFW_OPENED));
    }
    
    delete gameWindow;
    
    glfwTerminate();
    return 0;
}
