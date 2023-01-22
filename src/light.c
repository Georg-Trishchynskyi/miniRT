
#include "../inc/minirt.h"

//add triangle
t_p3    calculate_base_reflection(t_p3 inter_p, t_p3 d, t_figures *fig){
    t_p3 refl;
	t_p3 bump_norm;
    
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
		if (fig->material.bump != NULL)
		{
			bump_norm = sample_bump_map(inter_p, fig);
			refl = bump_norm;
		}
		
	}
    else if(fig->flag == PL)
        refl = fig->figures.pl.orient;
	else if(fig->flag == CY)
		refl = fig->figures.cy.normal;
	else if(fig->flag == HY)
		refl = hyberboloid_normal(inter_p, fig->figures.hy);
	else if(fig->flag == TR)
		refl = calculate_triangle_normal(fig->figures.tr);
    return refl;
}

bool	is_blocked(t_p3 dir_to_light, t_p3 inter_p, t_figures *fig)
{
	double	inter;

	while (fig)
	{
		if(fig->flag == SP && fig->material.refract <= 0 )
			inter = sphere_intersection(dir_to_light, inter_p, fig);
		else if(fig->flag == PL)
			inter = plane_intersection(dir_to_light, inter_p, fig->figures.pl.orient, fig->figures.pl.centr);
		else if(fig->flag == HY)
			inter = hyperboloid_intersection(dir_to_light, inter_p, fig->figures.hy);
		else if(fig->flag == CY)
			inter = cylinder_intersection(dir_to_light, inter_p, fig);
		else if(fig->flag == TR)
			inter = trinagle_intersection(dir_to_light, inter_p, fig->figures.tr);
		if(inter > 1e-4 && inter < 1)
			return true;
		fig = fig->next;
	}
	return false;
}

double calculate_gloss(t_p3 norm, t_p3 dir_to_light, t_figures figure, t_lights *light, t_p3 view_vec)
{
	t_p3	R_vec;

	R_vec = _substruct(_multy(_multy(norm, 2), _dot(norm, dir_to_light)), dir_to_light);
	if (_dot(R_vec, view_vec) > 0)
	{
		return (light->light.scale * powf(vcos(R_vec, view_vec), figure.material.gloss));
	}
	else
		return (0);
}

void	add_coeficient(t_p3 *rgb, double coef, t_p3 color)
{
	(*rgb).x += coef * color.x / 255;
	(*rgb).y += coef * color.y / 255;
	(*rgb).z += coef * color.z / 255;
}

int		rgb_to_int(t_p3 color, t_p3 rgb)
{
	rgb.x = rgb.x * color.x;
	rgb.y = rgb.y * color.y;
	rgb.z = rgb.z * color.z;

	rgb.x = rgb.x > 255 ? 255 : rgb.x;
	rgb.y = rgb.y > 255 ? 255 : rgb.y;
	rgb.z = rgb.z > 255 ? 255 : rgb.z;
	return (((int)rgb.x << 16) | ((int)rgb.y << 8) | (int)rgb.z);
}

//change figure to pointer
int	calculate_light(t_p3 norm, t_p3 inter_p, t_scene *scene, t_p3 view_vec, t_figures figure)
{
	double ret_light;
	double test_light;
	t_lights *light;
	t_p3 dir_to_light;
	t_p3	rgb;

	light = scene->lights;
	ret_light = 0.0f;
	rgb = new_vec(0,0,0);
	add_coeficient(&rgb, scene->a_scale, scene->a_color);
	while (light)
	{
		dir_to_light = _substruct(light->light.pos, inter_p);
		if (!is_blocked(dir_to_light, inter_p, scene->figures))
		{
			if (_dot(norm, dir_to_light) > 0/*insurse that we dont lower our light because of light souces that cosinus lower than 0*/)
			{
				ret_light = (light->light.scale * vcos(norm, dir_to_light));
				add_coeficient(&rgb, ret_light, light->light.rgb);
			}
			if (figure.material.gloss != -1)
			{
				ret_light = calculate_gloss(norm, dir_to_light, figure, light, view_vec);
				add_coeficient(&rgb, ret_light, light->light.rgb);
			}
		}
		light = light->next;
	}
	return rgb_to_int(get_collor_fig(&figure, inter_p), rgb);
}
