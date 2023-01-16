
#include "../inc/minirt.h"

//add triangle
t_p3    calculate_base_reflection(t_p3 inter_p, t_p3 d, t_figures *fig){
    t_p3 refl;
    
    if(fig->flag == SP)
	{
        refl = _substruct(inter_p, fig->figures.sp.centr);
		if (vcos(d, refl) > 0)
		{
			refl = _multy(refl, -1);
			fig->figures.sp.inside = 1;
		}
		else
			fig->figures.sp.inside = 0;
	}
    if(fig->flag == PL)
        refl = fig->figures.pl.orient;
	if(fig->flag == CY)
		refl = fig->figures.cy.normal;
	if(fig->flag == HY)
		refl = hyberboloid_normal(inter_p, fig->figures.hy);
    return refl;
}

bool	is_blocked(t_p3 dir_to_light, t_p3 inter_p, t_figures *fig)
{
	float	inter;

	while (fig)
	{
		if(fig->flag == SP && fig->material.refract <= 0)
			inter = sphere_intersection(dir_to_light, inter_p, fig);
		else if(fig->flag == PL)
			inter = plane_intersection(dir_to_light, inter_p, fig->figures.pl.orient, fig->figures.pl.centr);
		else if(fig->flag == HY)
			inter = hyperboloid_intersection(dir_to_light, inter_p, fig->figures.hy);
		if(inter > 1e-4 && inter < 1)
			return true;
		fig = fig->next;
	}
	return false;
}

float	calculate_light(t_p3 norm, t_p3 inter_p, t_scene *scene, t_p3 view_vec, t_figures figure)
{
	float ret_light;
	t_lights *light;
	t_p3 dir_to_light;
	t_p3	R_vec;
	
	// t_p3	rgb;

	// add_light();
	light = scene->lights;
	ret_light = 0.0f;
	ret_light += scene->a_scale; 
	while (light)
	{
		dir_to_light = _substruct(light->light.pos, inter_p);
		R_vec = _substruct(_multy(_multy(norm, 2), _dot(norm, dir_to_light)), dir_to_light);
		if (!is_blocked(dir_to_light, inter_p, scene->figures))
		{
			if (_dot(norm, dir_to_light) > 0/*insurse that we dont lower our light because of light souces that cosinus lower than 0*/)
			{
				ret_light += (light->light.scale * _dot(norm, dir_to_light)) / (_lenth(norm) * _lenth(dir_to_light));//dot(a, b)/len(a)*len(b) == cosinus between vectors
			}
			if (figure.material.gloss != -1)
			{
				if (_dot(R_vec, view_vec) > 0)
				{
					ret_light += light->light.scale * powf(_dot(R_vec, view_vec) / (_lenth(R_vec) * _lenth(view_vec)), figure.material.gloss);
				}
				
			}
		}
		light = light->next;
	}
	return (ret_light);
}
