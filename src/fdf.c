/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:48:18 by lminta            #+#    #+#             */
/*   Updated: 2019/10/21 20:23:43 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_init_position(t_map *map)
{
	t_move	mv;
	t_xy	win;

	ft_mlx_init(1300, 1300, "ebobo");
	mv = g_mv(0, 0);
	win = g_win(0, 0);
	if (win.x / map->size_w > win.y / map->size_h)
		mv.zoom = win.y / map->size_h;
	else
		mv.zoom = g_win(0, 0).x / map->size_w;
	win.intery = mv.zoom;
	mv.rl = win.x / 2 - (map->size_w / 2) * mv.zoom;
	mv.ud = win.y / 2 - (map->size_h / 2) * mv.zoom;
	mv.alpha = M_PI * 35.264 / 180.0;
	mv.beta = M_PI * 45.0 / 180.0;
	g_win(&win, 1);
	g_mv(&mv, 3);
	g_end_c(fill_color(255, 255, 255), 1);
}

static void		fill_init(t_map *map, int argc, char **argv)
{
	t_move	mv;

	if (argc != 2)
		if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f')
		{
			mv = upside(32);
			g_mod(5, 1);
			g_end_c(fill_color(255, 255, 255), 1);
			g_color(fill_color(0, 0, 0), 1);
			mv.rl = 100;
			mv.ud = 100;
			g_mv(&mv, 3);
		}
	draw_map(map);
}

int				main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f')
			map = fill_my_fdf(argv[2]);
		else
		{
			ft_putstr("usage: [-f] fdf filename\n");
			return (0);
		}
	}
	else
		map = read_map(argv[1]);
	if (!map)
	{
		ft_putstr("\nSomething went wrong :(\n");
		return (0);
	}
	set_init_position(map);
	fill_init(map, argc, argv);
	mlx_hook(g_mlx(0, 0).win_ptr, 2, 0, &cam_fdf, map);
	mlx_hook(g_mlx(0, 0).win_ptr, 17, 0, &press_x, map);
	mlx_loop(g_mlx(0, 0).mlx_ptr);
	return (0);
}
