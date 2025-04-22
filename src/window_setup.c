#include "../include/square_physics.h"

GLFWwindow* create_window(int width, int height, const char *title)
{
    if (!glfwInit())
    {
        fprintf(stderr, "Erreur init GLFW\n");
        return NULL;
    }

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Erreur création fenêtre\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
    return window;
}

void setup_projection(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}