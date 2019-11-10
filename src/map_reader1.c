/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:00:16 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 20:21:45 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			create_map(t_map **map)
{
	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	(*map)->size_h = 0;
	(*map)->size_w = -1;
	(*map)->min = 2147483647;
	(*map)->max = -2147483648;
	return (1);
}

int			field_create(t_map *map)
{
	int i;

	i = 0;
	if (!(map->map = (t_point **)malloc(sizeof(t_point *) * map->size_h)))
	{
		free(map);
		return (0);
	}
	while (i < map->size_h)
	{
		if (!(map->map[i] = (t_point *)malloc(sizeof(t_point) * map->size_w)))
		{
			map->size_h = i;
			map_clean(map);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	stage_one(char *fname, t_map **map)
{
	int		fd;

	if ((fd = open(fname, O_RDONLY)) <= 0)
	{
		perror("Error detected");
		return (0);
	}
	if (!(create_map(map)))
		return (0);
	if (!(map_size(*map, fd)))
		return (0);
	if (!(field_create(*map)))
		return (0);
	close(fd);
	return (1);
}

static int	stage_two(char *fname, t_map *map)
{
	int		fd;
	int		err;
	char	*line;

	if ((fd = open(fname, O_RDONLY)) <= 0)
	{
		perror("Error detected");
		free(map);
		return (0);
	}
	while ((err = get_next_line(fd, &line)) > 0)
	{
		parse(map, line);
		free(line);
	}
	free(line);
	if (err < 0)
	{
		perror("Error detected");
		map_clean(map);
		return (0);
	}
	close(fd);
	return (1);
}

t_map		*read_map(char *fname)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(stage_one(fname, &map)))
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
	if (!(stage_two(fname, map)))
		return (NULL);
	return (map);
}
