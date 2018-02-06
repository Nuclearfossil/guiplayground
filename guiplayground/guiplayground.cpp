// guiplayground.cpp : Defines the entry point for the application.
//

#include "guiplayground.h"

#define GLEW_STATIC
#include "GL/glew.h"

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "stb.h"

#include <Windows.h>

void WindowCloseCallback(GLFWwindow* window);
void WindowSizeCallback(GLFWwindow* window, int width, int height);
void WindowPositionCallback(GLFWwindow* window, int xpos, int ypos);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialize a window
    window = glfwCreateWindow(1024, 720, "OpenGL Test Window", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Set the context to the current window
    glfwMakeContextCurrent(window);

    // Initialize base windows callbacks
    glfwSetWindowCloseCallback(window, WindowCloseCallback);
    glfwSetWindowSizeCallback(window, WindowSizeCallback);
    glfwSetWindowPosCallback(window, WindowPositionCallback);

    glewInit();
    glewExperimental = GL_TRUE;

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Tear down
    glfwTerminate();
    return 0;
}

void WindowCloseCallback(GLFWwindow* window)
{
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void WindowSizeCallback(GLFWwindow* window, int width, int height)
{

}

void WindowPositionCallback(GLFWwindow* window, int xpos, int ypos)
{

}