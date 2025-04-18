#ifndef WINDOW_H
# define WINDOW_H

# include <GLFW/glfw3.h>
# include <stdio.h>

typedef struct s_carre
{
    float 		p1[2];
    float		p2[2];

	float			x_force;
	float			y_force;
} t_carre;

// Fonctions de dessin
void    draw_triangle(float p1[2], float p2[2], float p3[2]);
void    draw_rectangle(float p1[2], float p2[2]);
void    draw_square(t_carre c);
void    draw_unit(t_carre *c);

// Fonctions de manipulation de carré
void    square_init(t_carre *c, int mid_x, int mid_y, int rayon);
void    add_x_square(t_carre *c, int v);
void    add_y_square(t_carre *c, int v);
void    rm_x_square(t_carre *c, int v);
void    rm_y_square(t_carre *c, int v);

// Fonctions GLFW
GLFWwindow* create_window(int width, int height, const char *title);
void        setup_projection(int width, int height);
void        window_init(void);

#endif