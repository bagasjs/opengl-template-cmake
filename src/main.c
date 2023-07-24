#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void glfw_error_callback(int err, const char* description) {
    printf("[ERROR %d]: %s\n", err, description);
}

int main(void) {
    glfwSetErrorCallback(glfw_error_callback);

    if(glfwInit() != GLFW_TRUE) {
        printf("Failed to initialize GLFW\n");
        return EXIT_FAILURE;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Template", NULL, NULL);
    if(window == NULL) {
        printf("Failed to create window\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();        
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
