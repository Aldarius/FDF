/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:51:09 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:12:27 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_map_fill	*print_error(int a)
{
	if (a == 0)
		ft_putstr("usage: ./fillit source_file\n");
	if (a == 1)
		ft_putstr("error\n");
	return (0);
}

void				re_list(t_tetr **last)
{
	t_tetr	*current;
	t_tetr	*buff;

	current = 0;
	buff = (*last)->next;
	while (buff)
	{
		buff = (*last)->next;
		(*last)->next = current;
		current = (*last);
		if (buff)
			(*last) = buff;
	}
}

t_map_fill			*fillit_main(char *argv)
{
	t_map_fill	*map;
	t_tetr		*last;
	int			num;
	int			fd;

	fd = open(argv, O_RDONLY);
	if (!(num = read_all(fd, &last)))
		return (print_error(1));
	if (!(map = map_create(ft_sqrt(num * 4))))
	{
		list_free(last);
		return (0);
	}
	while (!(fillit(map, last)))
		re_map(&(map->map), (map->size)++);
	list_free(last);
	close(fd);
	return (map);
}
