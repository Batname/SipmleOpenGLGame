#include <GL/glfw.h>

int main(int argc, const char * argv[]) {
    bool running = true;
    glfwInit();
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    glfwOpenWindow(800*16/9, 800, 8, 8, 8, 8, 0, 0, GLFW_WINDOW);
    glfwSetWindowTitle("OpenGL title");
    
    while(running) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers();

        running = glfwGetWindowParam(GLFW_OPENED);
    }
    
    glfwTerminate();
    return 0;
}
