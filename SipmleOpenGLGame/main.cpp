#include "GameWindow.hpp"

#include <GL/glfw.h>

#define Updates_Per_Second 60

GameWindow * gameWindow;

int main(int argc, const char * argv[]) {

    glfwInit();
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    glfwOpenWindow(800*16/9, 800, 8, 8, 8, 8, 0, 0, GLFW_WINDOW);
    glfwSetWindowTitle("OpenGL Game");
    glfwSwapInterval(0);
    
    gameWindow = new GameWindow(true);
    
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;
    
    while(gameWindow->getRunning()) {
        gameWindow->render();
        
        deltaTime += (glfwGetTime() - lastTime) * Updates_Per_Second;
        lastTime = glfwGetTime();
        while (deltaTime >= 1.0f) {
            gameWindow->update();
            --deltaTime;
        }

        gameWindow->setRuning(glfwGetWindowParam(GLFW_OPENED));
    }
    
    delete gameWindow;
    
    glfwTerminate();
    return 0;
}
