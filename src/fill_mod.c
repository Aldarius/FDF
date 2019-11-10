/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:44:49 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 21:59:51 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		map_fix(t_map *map)
{
	int		i;
	int		j;
	t_color	grad;

	i = 0;
	grad = fill_color(0, 0, 0);
	grad = gradient(g_color(grad, 0), g_end_c(grad, 0), map->max - map->min);
	while (i < map->size_h)
	{
		j = 0;
		while (j < map->size_w)
		{
			map->map[i][j].color = rgb_to_int(sum_collors(g_color(grad, 0),
			grad, map->map[i][j].z));
			j++;
		}
		i++;
	}
}

static t_color	wat_cal(t_point cl1, t_point cl2)
{
	t_color	grad;

	grad = fill_color(0, 0, 0);
	if (cl1.color == cl2.color && cl1.z && cl2.z)
		return (g_end_c(grad, 0));
	else
		return (g_color(grad, 0));
}

void			fill_mod(t_map *map)
{
	int		i;
	int		j;
	t_color	cl;

	i = -1;
	map_fix(map);
	while (++i < map->size_h)
	{
		j = -1;
		while (++j < map->size_w)
		{
			if (i + 1 < map->size_h)
			{
				cl = wat_cal(map->map[i + 1][j], map->map[i][j]);
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j, i + 1, map->map[i + 1][j].z), cl, cl);
			}
			if (j + 1 < map->size_w)
			{
				cl = wat_cal(map->map[i][j], map->map[i][j + 1]);
				draw_vector(create_vector(j, i, map->map[i][j].z),
create_vector(j + 1, i, map->map[i][j + 1].z), cl, cl);
			}
		}
	}
}
