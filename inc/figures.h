#ifndef FIGURES_H
#define FIGURES_H

typedef struct	s_sphere
{
	t_vector	*centr;
	float		radius;
}				t_sphere;

typedef struct	s_figures
{
	t_sphere *sp;
}				t_figures;


#endif