
#include "../inc/minirt.h"

t_p3	look_at_pixel(t_p3 d, t_p3 cam_nv)
{
	t_p3	ref_up;
	t_p3	x_axis;
	t_p3	y_axis;
	t_p3	rotated;

	ref_up = new_vec(0, 1, 0);
	if (cam_nv.y == 1 || cam_nv.y == -1)
		x_axis = cam_nv.y == 1 ? (t_p3) {1, 0, 0} : (t_p3) {-1, 0, 0};
	else
		x_axis = _cross(ref_up, cam_nv);
	x_axis = _cross(ref_up, _norm(cam_nv));
	y_axis = _cross(_norm(cam_nv), x_axis);
	rotated = _add(_multy(x_axis, d.x), cam_nv);
	rotated = _add(_multy(y_axis, d.y), rotated);
	return (rotated);
}

t_p3	get_screen_coord(int x, int y, t_scene *scene)
{
	t_p3	ret;

	ret.x = ((2 * (x + 0.5) / scene->width) - 1) \
	* scene->aspect_ratio * scene->camera->fov_l;
	ret.y = (1 - (2 * (y + 0.5) / scene->height)) * scene->camera->fov_l;
	ret.z = -1;
	ret = look_at_pixel(ret, scene->camera->direct);
	return (ret);
}


void	solve_sphere(t_p3 d, t_p3 cam_o, t_sphere sp, double x[2]){
	t_p3	p;//makes vector p that goes from sphere origin to intersection
	double	disc;
	t_p3	sp_o;
	double	r;
	double	quad_kof[3];

	r = sp.radius;
	sp_o = sp.centr;
	p = _substruct(cam_o, sp_o);
	quad_kof[0] = _dot(d, d);
	quad_kof[1] = 2 * _dot(p, d);
	quad_kof[2] = _dot(p, p) - r * r;
	disc = quad_kof[1] * quad_kof[1] - 4 * quad_kof[0] * quad_kof[2];
	if (disc < 0)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return ;
	}
	x[0] = (-quad_kof[1] + sqrt(disc)) / (2 * quad_kof[0]);
	x[1] = (-quad_kof[1] - sqrt(disc)) / (2 * quad_kof[0]);
}

double	sphere_intersection(t_p3 d, t_p3 o, t_figures *lst)
{
	double	closest;
	double	x[2];
	t_p3	ip1;
	t_p3	ip2;

	closest = INFINITY;
	solve_sphere(d, o, lst->figures.sp, x);
	if (x[0] > EPSILON && x[0] < INFINITY)
		closest = x[0];
	if (x[1] > EPSILON && x[1] < INFINITY)
		closest = x[1] < x[0] ? x[1] : closest;
	return (closest);
	ip1 = _add(o, _multy(d, x[0]));
	ip2 = _add(o, _multy(d, x[1]));
	if (ip1.y >= lst->figures.sp.centr.y && ip2.y >= lst->figures.sp.centr.y)
		return (x[0] < x[1] ? x[0] : x[1]);
	else if (ip1.y >= lst->figures.sp.centr.y)
		return (x[0]);
	else if (ip2.y >= lst->figures.sp.centr.y)
		return (x[1]);
	return (INFINITY);
}

double	plane_intersection(t_p3 d, t_p3 cam_o, t_p3 pl_n, t_p3 pl_o){
	double	inter_proj;//projection of intersecting normal and direction of camera
	double	inter;

	inter_proj = _dot(d, pl_n);
	if(inter_proj == 0)//this means that plane doesnt intersect with the ray
		return (INFINITY);
	inter = _dot(_substruct(pl_o, cam_o)/*vector to posible inter*/, pl_n) / inter_proj;
	//if inter == 0 vector is || to plane
	//if < 0 its on the oposite side of the cam
	//if > 0 it intersects
	if (inter <= 0)
		return (INFINITY);
	else
		return (inter);
}

bool	check_p_in_borders(t_p3 p1, t_p3 p2, t_p3 p3, t_p3 inter_p)
{
	t_p3	v1;
	t_p3	v2;
	t_p3	v3;
	t_p3	cross1;
	t_p3	cross2;

	v1 = _substruct(p2, p1);
	v2 = _substruct(p3, p1);
	v3 = _substruct(inter_p, p1);
	cross1 = _cross(v1, v2);
	cross2 = _cross(v1, v3);
	if (_dot(cross1, cross2) / _lenth(cross1) * _lenth(cross2) < 0)
		return (false);
	return (true);
}

t_p3	calculate_triangle_normal(t_triangle tri)
{
	return (_cross(_substruct(tri.p1, tri.p2), _substruct(tri.p1, tri.p3)));
}

double	trinagle_intersection(t_p3 d, t_p3 cam_o, t_triangle tri){
	t_p3	tri_norm;
	double	plane_inter;
	t_p3	inter_p;

	tri_norm = calculate_triangle_normal(tri);
	plane_inter = plane_intersection(d, cam_o, tri_norm, tri.p1);
	inter_p = _add(cam_o, _multy(d, plane_inter));
	if (!check_p_in_borders(tri.p1, tri.p2, tri.p3, inter_p))
		return (INFINITY);
	if (!check_p_in_borders(tri.p3, tri.p1, tri.p2, inter_p))
		return (INFINITY);
	if (!check_p_in_borders(tri.p2, tri.p3, tri.p1, inter_p))
		return (INFINITY);
	return (plane_inter);
}

double	try_intersections(t_p3 d, t_p3 cam_o, t_figures *fig, t_figures *closest_fig)
{
	double	inter_dist;
	double	closest_inter;

	closest_inter = INFINITY;
	while (fig)
	{
		if (fig->flag == SP)
			inter_dist = sphere_intersection(d, cam_o, fig);
		else if (fig->flag == PL)
			inter_dist = plane_intersection(d, cam_o, \
			fig->figures.pl.orient, fig->figures.pl.centr);
		else if (fig->flag == TR)
			inter_dist = trinagle_intersection(d, cam_o, fig->figures.tr);
		else if (fig->flag == CY)
			inter_dist = cylinder_intersection(d, cam_o, fig);
		else if (fig->flag == HY)
			inter_dist = hyperboloid_intersection(d, cam_o, fig->figures.hy);
		if (inter_dist < closest_inter && inter_dist > 1e-3){
			closest_inter = inter_dist;
			*closest_fig = *fig;
		}
		fig = fig->next;
	}
	return (closest_inter);
}

t_p3	ray_reflect(t_p3 dir, t_p3 normal)
{
	return (_substruct(_multy(normal, 2 * _dot(normal, dir)) , dir));
}

t_p3	ray_refraction(t_p3 dir, t_p3 normal, t_figures *cl_figure)
{
	double	k;
	double	eta;
	double	etai;
	double	etat;
	double	cosi;

	cosi = _dot(dir, normal);
	etai = 1;
	etat = cl_figure->material.refract;
	if (cl_figure->figures.sp.inside == 1)
	{
		k = etai;
		etai = etat;
		etat = k;
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - cosi * cosi);
	if (k < 0)
		return (ray_reflect(_multy(dir, -1), normal));
	else
		return (_add(_multy(dir, eta), _multy(normal, (eta * cosi) - sqrt(k))));
}

int trace_ray(t_p3 d, t_p3 O, t_scene *scene, int depth)
{
	double		closest_inter;
	t_figures	closest_figure;
	t_p3		reflect_norm;
	t_p3		inter_p;
	int			temp_color;
	int			reflect_color;
	
	closest_figure.flag = 0;
	d = _norm(d);
	closest_inter = try_intersections(d, O, scene->figures, &closest_figure);
	if(closest_inter == INFINITY)
		return (scene->background);
	inter_p = _add(O, _multy(d, closest_inter));
	reflect_norm = _norm(calculate_base_reflection(inter_p, d, &closest_figure));
	temp_color = calculate_light(reflect_norm, inter_p, scene, _multy(d, -1), closest_figure);
	if (closest_figure.material.refract > 0)
		temp_color = trace_ray(ray_refraction(d, reflect_norm, &closest_figure), inter_p, scene, depth);
	if (depth > 0 && closest_figure.material.reflective > 0)
		reflect_color = trace_ray(ray_reflect(_multy(d, -1), reflect_norm), inter_p, scene, depth - 1);
	return (_cadd(_cproduct(temp_color, (1 - closest_figure.material.reflective)), _cproduct(reflect_color, closest_figure.material.reflective)));
}

void render_scene(t_scene *scene, int thread_id)
{
	int y;
	int x;
	t_p3 dir_vec;
	int color;
	int lines_to_render;
  
	lines_to_render = scene->height / NUM_THREADS;
	y = thread_id * lines_to_render;
	// if (scene->mlx->img)
	// {
	// 	fprintf(stderr, "%f", scene->camera->pos.x);
	// 	mlx_destroy_image(scene->mlx->mlx, scene->mlx->img);
	// 	scene->mlx->img = mlx_new_image(scene->mlx->mlx, scene->width, scene->height);
	// }
	while (y < lines_to_render * (thread_id + 1))
	{
		x = 0;
		while (x < scene->width)
		{
			dir_vec = get_screen_coord(x, y, scene);		          
			color = trace_ray(dir_vec, scene->camera->pos, scene, 2);
            my_mlx_pixel_put(scene, x, y, color);
			if(thread_id == NUM_THREADS - 1) 
				printf("\rRendering scene... [%f%%]", (100 * (y % lines_to_render) / (float)lines_to_render));
			// exit(0);
			x++;
		}
		y++;
	}
}
