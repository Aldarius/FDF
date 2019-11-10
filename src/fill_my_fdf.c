/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_my_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:29:16 by lminta            #+#    #+#             */
/*   Updated: 2019/06/19 22:14:37 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	stage_one(t_map **map, int size)
{
	if (!(create_map(map)))
		return (0);
	(*map)->size_h = size;
	(*map)->size_w = size;
	if (!(field_create(*map)))
		return (0);
	return (1);
}

static void	stage_two(t_map *map, t_map_fill *fill)
{
	int			i;
	int			j;

	map->max = 0;
	map->min = 0;
	i = 0;
	while (i < fill->size)
	{
		j = 0;
		while (j < fill->size)
		{
			if (fill->map[i][j])
				map->map[i][j].z = fill->map[i][j] - 'A' + 2;
			map->map[i][j].color = -1;
			if (map->map[i][j].z > map->max)
				map->max = map->map[i][j].z;
			j++;
		}
		i++;
	}
	fill_map_clean(fill->map, fill->size);
}

t_map		*fill_my_fdf(char *fname)
{
	t_map		*map;
	t_map_fill	*fill;
	int			i;
	int			j;

	if (!(fill = fillit_main(fname)))
		return (NULL);
	print_map(fill);
	if (!(stage_one(&map, fill->size)))
		return (NULL);
	i = 0;
	while (i < map->size_h)
	{
		j = 0;
		while (j < map->size_w)
		{
			map->map[i][j].z = 0;
			j++;
		}
		i++;
	}
	stage_two(map, fill);
	free(fill);
	return (map);
}
