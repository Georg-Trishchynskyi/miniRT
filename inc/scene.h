#ifndef SCENE_H
#define SCENE_H

typedef struct	s_cams
{
	t_vector	*pos;
	t_vector	*direct;
	float		angle;
}				t_cams;


typedef struct	s_scene
{
	t_cams		*camera;
	t_figures	figures;

}				t_scene

//CMAERA
t_cams *new_camera(t_vector *pos, t_vector *dir, float angle);

//SCENE

#endif