/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:57:06 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:13:46 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_mod(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->size_h)
	{
		j = 0;
		while (j < map->size_w)
		{
			if (i + 1 < map->size_h)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j, i + 1, map->map[i + 1][j].z),
int_to_rgb(map->map[i][j].color), int_to_rgb(map->map[i + 1][j].color));
			if (j + 1 < map->size_w)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j + 1, i, map->map[i][j + 1].z),
int_to_rgb(map->map[i][j].color), int_to_rgb(map->map[i][j + 1].color));
			j++;
		}
		i++;
	}
}

void	pride_mod(t_map *map)
{
	int		i;
	int		j;
	t_color	grad;

	i = 0;
	grad = fill_color(0, 0, 0);
	grad = gradient(g_color(grad, 0), g_end_c(grad, 0), map->size_h);
	while (i < map->size_h)
	{
		j = 0;
		while (j < map->size_w)
		{
			if (i + 1 < map->size_h)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j, i + 1, map->map[i + 1][j].z), sum_collors(g_color(grad, 0),
grad, i), sum_collors(g_color(grad, 0), grad, i + 1));
			if (j + 1 < map->size_w)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j + 1, i, map->map[i][j + 1].z),
sum_collors(g_color(grad, 0), grad, i), sum_collors(g_color(grad, 0), grad, i));
			j++;
		}
		i++;
	}
}

void	mono_mod(t_map *map)
{
	int		i;
	int		j;
	t_color	grad;

	i = 0;
	grad = fill_color(0, 0, 0);
	while (i < map->size_h)
	{
		j = 0;
		while (j < map->size_w)
		{
			if (i + 1 < map->size_h)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j, i + 1, map->map[i + 1][j].z),
g_color(grad, 0), g_color(grad, 0));
			if (j + 1 < map->size_w)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j + 1, i, map->map[i][j + 1].z),
g_color(grad, 0), g_color(grad, 0));
			j++;
		}
		i++;
	}
}

void	grad_mod(t_map *map)
{
	int		i;
	int		j;
	t_color	grad;

	i = -1;
	grad = fill_color(0, 0, 0);
	grad = gradient(g_color(grad, 0), g_end_c(grad, 0), map->max - map->min);
	while (++i < map->size_h)
	{
		j = 0;
		while (j < map->size_w)
		{
			if (i + 1 < map->size_h)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j, i + 1, map->map[i + 1][j].z),
sum_collors(g_color(grad, 0), grad, map->map[i][j].z),
sum_collors(g_color(grad, 0), grad, map->map[i + 1][j].z));
			if (j + 1 < map->size_w)
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j + 1, i, map->map[i][j + 1].z),
sum_collors(g_color(grad, 0), grad, map->map[i][j].z),
sum_collors(g_color(grad, 0), grad, map->map[i][j + 1].z));
			j++;
		}
	}
}
