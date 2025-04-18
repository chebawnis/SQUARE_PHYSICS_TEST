#include "../include/square_physics.h"

#define G_FORCE 1
#define WINDOW_X_SIZE 1000
#define WINDOW_Y_SIZE 1000
#define ENERGY_LOSS 0.99
#define HEAVINESS 0.0001



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

void    draw_triangle(float p1[2], float p2[2], float p3[2])
{
    glBegin(GL_TRIANGLES);
    glVertex2f(p1[0], p1[1]);
    glVertex2f(p2[0], p2[1]);
    glVertex2f(p3[0], p3[1]);
    glEnd();
}

void    draw_rectangle(float p1[2], float p2[2])
{
    float p3[2] = {p2[0], p1[1]};
    float p4[2] = {p1[0], p2[1]};

    glColor3f(1.0f, 0.0f, 0.0f);
    draw_triangle(p1, p3, p2);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_triangle(p1, p4, p2);
}

void    square_init(t_carre *c, int mid_x, int mid_y, int rayon)
{
    c->p1[0] = mid_x - rayon;
    c->p1[1] = mid_y - rayon;
    c->p2[0] = mid_x + rayon;
    c->p2[1] = mid_y + rayon;

    c->x_force = 0;
    c->y_force = 0;
}

void    draw_square(t_carre c)
{
    draw_rectangle(c.p1, c.p2);
}

void    add_x_square(t_carre *c, int v)
{
    c->p1[0] += v;
    c->p2[0] += v;
}

void    add_y_square(t_carre *c, int v)
{
    c->p1[1] += v;
    c->p2[1] += v;
}

void    update_forces(t_carre *c)
{
    add_x_square(c, c->x_force);
    add_y_square(c, c->y_force);
}

void    update_physics(t_carre *c)
{
    c->y_force += (G_FORCE - c->p1[1]) * HEAVINESS;

    update_forces(c);

    // if (c->x_force <= 0.00000001)
    //     c->x_force = 0;
    // if (c->y_force <= 0.00000001)
    //     c->y_force = 0;

    c->x_force *= ENERGY_LOSS;
    c->y_force *= ENERGY_LOSS;
}

void    draw_unit(t_carre *c)
{
    draw_square(*c);
    update_physics(c);
}



void window_init(void)
{
    GLFWwindow* window = create_window(WINDOW_X_SIZE, WINDOW_Y_SIZE, "Ma fenêtre");
    if (!window) return;
    setup_projection(WINDOW_X_SIZE, WINDOW_Y_SIZE);


    t_carre c1;

    square_init(&c1, 500, 500, 50);    

    // Boucle principale
    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_unit(&c1);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main(void)
{
    window_init();
    return 0;
}
