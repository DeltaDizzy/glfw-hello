#include <cstddef>
#include <print>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void on_window_resize(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

int main() {

    constexpr unsigned int width{600};
    constexpr unsigned int height{600};

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(width, height, "Hello", NULL, NULL);
    if (window == NULL) {
        std::println("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, on_window_resize); // register resize callback
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::println("Failed to initialize GLAD\n");
        return -1;
    }

    while (!glfwWindowShouldClose(window)) { // render loop
        // get key inputs
        process_input(window);

        // render commands

        glad_glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glad_glClear(GL_COLOR_BUFFER_BIT);

        // display
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void on_window_resize(GLFWwindow* window, int width, int height) {
    glad_glViewport(0, 0, width, height);   
}

void process_input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
