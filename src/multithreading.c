/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:37:07 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 15:33:49 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	*render_thread(void *ptr)
{
	t_thread_data	*data;

	data = (t_thread_data *)ptr;
	render_scene_with_thread(data->scene, data->index);
	return (NULL);
}

void	start_threads(t_thread_data thread_data[NUM_THREADS])
{
	pthread_t	threads[NUM_THREADS];
	int			i;

	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(threads[i++], NULL);
}

void	multithreaded_render(t_scene *scene)
{
	t_thread_data	thread_data[NUM_THREADS];
	int				i;

	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].scene = scene;
		thread_data[i].index = i;
		i++;
	}
	start_threads(thread_data);
}
