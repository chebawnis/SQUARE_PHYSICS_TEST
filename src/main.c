#include "../include/square_physics.h"

double get_time_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

void    update_forces(t_square *c, double delta_time)
{
    add_x_square(c, c->x_v);
    add_y_square(c, c->y_v);
    if (c->middle[1] - c->size < 0 || c->middle[1] + c->size > WINDOW_Y_SIZE)
        c->y_v *= -1;
    if (c->middle[0] - c->size < 0 || c->middle[0] + c->size > WINDOW_X_SIZE)
        c->x_v *= -1;
}

void    update_physics(t_square *c, double delta_time)
{
    update_forces(c, delta_time);
    // printf("DELTA TIME = %f\n", delta_time);

    // c->x_v *= ENERGY_LOSS;
    // c->y_v *= ENERGY_LOSS;
}

void draw_unit(t_square *c, double delta_time)
{
    draw_square(*c);
    update_physics(c, delta_time);
}

void print_carre(t_square c)
{
    printf("position x = %f\n", c.middle[0]);
    printf("position y = %f\n", c.middle[1]);
    printf("vitesse x = %f\n", c.x_v);
    printf("vitesse y = %f\n", c.y_v);
    printf("taille = %d\n", c.size * 2);
    
}

void window_init(void)
{
    GLFWwindow* window = create_window(WINDOW_X_SIZE, WINDOW_Y_SIZE, "Squares Physics");
    if (!window) return;
    setup_projection(WINDOW_X_SIZE, WINDOW_Y_SIZE);


    double                  last_time = get_time_seconds();
    double                  delta_time;

    t_square *c = init_square_struct();
    print_carre(*c);
    
    // Boucle principale
    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        double current_time = get_time_seconds();
        delta_time = current_time - last_time;
        last_time = current_time;
        usleep(3900);

        draw_unit(c, delta_time);

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
