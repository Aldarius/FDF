/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:49:20 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 20:22:10 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				map_clean(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size_h)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	return (0);
}

static size_t	ft_len(char *line)
{
	size_t	len;
	size_t	i;

	if (!line)
		return (0);
	len = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			len++;
			while (ft_isspace(line[i]))
				i++;
		}
		i++;
	}
	len++;
	return (len);
}

int				map_size(t_map *map, int fd)
{
	int		len;
	int		err;
	char	*line;

	while ((err = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		if (ft_isspace(line[len - 1]))
			line[len - 1] = '\0';
		len = ft_len(line);
		if (len > map->size_w)
			map->size_w = len;
		map->size_h++;
		free(line);
	}
	free(line);
	if (err < 0)
	{
		perror("Error detected");
		free(map);
		return (0);
	}
	return (1);
}

void			parse(t_map *map, char *line)
{
	static int	nb = 0;
	int			i;

	i = 0;
	while (*line)
	{
		while (ft_isspace(*line) && *line)
			line++;
		map->map[nb][i].z = ft_atoi(line);
		if (map->map[nb][i].z > map->max)
			map->max = map->map[nb][i].z;
		if (map->map[nb][i].z < map->min)
			map->min = map->map[nb][i].z;
		map->map[nb][i].color = -1;
		while (!ft_isspace(*line) && *line)
		{
			if (*line == ',')
				map->map[nb][i].color = ft_atoi_base(line + 3, 16);
			line++;
		}
		i++;
	}
	nb++;
}
