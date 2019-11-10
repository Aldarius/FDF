/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:08:23 by lminta            #+#    #+#             */
/*   Updated: 2019/10/21 20:12:26 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_move	cam_zoom(int keycode)
{
	t_move	mv;

	mv = g_mv(0, 0);
	if (keycode == 69)
		mv.zoom += g_win(0, 0).intery / 50;
	else if (keycode == 78)
	{
		mv.zoom -= g_win(0, 0).intery / 50;
		if (mv.zoom <= g_win(0, 0).intery / 50)
			mv.zoom = g_win(0, 0).intery / 50;
	}
	else if (keycode == 49)
	{
		mv = g_mv(0, 2);
		g_mod(1, 1);
		g_end_c(fill_color(255, 255, 255), 1);
		g_color(fill_color(255, 255, 255), 1);
	}
	else
		mv = upside(keycode);
	return (mv);
}

static t_move	cam_rotate(int keycode)
{
	t_move	mv;

	mv = g_mv(0, 0);
	if (keycode == 0)
		mv.beta -= M_PI * 4.0 / 180.0;
	else if (keycode == 2)
		mv.beta += M_PI * 4.0 / 180.0;
	else if (keycode == 1)
		mv.alpha -= M_PI * 4.0 / 180.0;
	else if (keycode == 13)
		mv.alpha += M_PI * 4.0 / 180.0;
	else if (keycode == 12)
		mv.gamma -= M_PI * 4.0 / 180.0;
	else if (keycode == 14)
		mv.gamma += M_PI * 4.0 / 180.0;
	else if (keycode == 27)
		mv.contrast *= 0.9;
	else if (keycode == 24)
		mv.contrast /= 0.9;
	else
		mv = cam_zoom(keycode);
	return (mv);
}

int				cam_fdf(int keycode, t_map *map)
{
	t_move	mv;

	mv = g_mv(0, 0);
	if (keycode == 126)
		mv.ud -= 25;
	else if (keycode == 125)
		mv.ud += 25;
	else if (keycode == 124)
		mv.rl += 25;
	else if (keycode == 123)
		mv.rl -= 25;
	else if (keycode == 53)
	{
		map_clean(map);
		exit(0);
	}
	else
		mv = cam_rotate(keycode);
	g_mv(&mv, 1);
	mlx_clear_window(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr);
	draw_map(map);
	return (0);
}
