/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:21:28 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 21:58:49 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_mod(void)
{
	t_color col;

	col = fill_color(0, 0, 0);
	if (g_mod(0, 0) == 1)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_color(col, 0)), "map_mod");
	if (g_mod(0, 0) == 2)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_color(col, 0)), "mono_mod");
	if (g_mod(0, 0) == 3)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_color(col, 0)), "pride_mod");
	if (g_mod(0, 0) == 4)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_color(col, 0)), "grad_mod");
	if (g_mod(0, 0) == 5)
		mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10, 10,
		rgb_to_int(g_color(col, 0)), "fill_mod");
}

void		print_help(void)
{
	t_color col;

	col = fill_color(0, 0, 0);
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 250, rgb_to_int(g_color(col, 0)),
	"You can use ARROWS for movement");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 230, rgb_to_int(g_color(col, 0)),
	"QEWASD for rotation");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 210, rgb_to_int(g_color(col, 0)),
	"12345 for color modification");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 190, rgb_to_int(g_color(col, 0)),
	"< change base color, > change additional color");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 170, rgb_to_int(g_color(col, 0)),
	"Roughness buttons is +/-");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 150, rgb_to_int(g_color(col, 0)),
	"Zooming buttons is +/- on numeric keypad");
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr,
	10, g_win(0, 0).y - 130, rgb_to_int(g_color(col, 0)),
	"Press SPACE to restart program, U to upside-down view and ESC to exit");
}

void		print_text(void)
{
	t_color buff;

	buff = fill_color(0, 0, 0);
	buff = g_color(buff, 0);
	if (!(rgb_to_int(g_color(buff, 0))))
		g_color(fill_color(255, 255, 255), 1);
	print_mod();
	mlx_string_put(g_mlx(0, 0).mlx_ptr, g_mlx(0, 0).win_ptr, 10,
	g_win(0, 0).y - 30, rgb_to_int(g_color(buff, 0)), "Press H for help");
	if (g_help(0, 0))
		print_help();
	g_color(buff, 1);
}

int			press_x(t_map *map)
{
	map_clean(map);
	exit(0);
}
