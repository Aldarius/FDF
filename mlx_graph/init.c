/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:30:54 by lminta            #+#    #+#             */
/*   Updated: 2019/06/14 16:18:08 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_line.h"

static void	ptr_init(int a, int b, char *str)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, a, b, str);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, a, b);
	mlx.image = mlx_get_data_addr(mlx.img_ptr, &(mlx.bits_per_pixel),
	&(mlx.size_line), &(mlx.endian));
	g_mlx(&mlx, 1);
}

void		ft_mlx_init(int a, int b, char *str)
{
	t_move	mv;
	t_xy	win;

	ptr_init(a, b, str);
	g_borders(fill_borders(0, 0, a, b), 1);
	g_color(fill_color(255, 255, 255), 1);
	mv.ud = 0;
	mv.rl = 0;
	mv.alpha = 0;
	mv.beta = 0;
	mv.gamma = 0;
	mv.zoom = 1;
	mv.contrast = 1;
	g_mv(&mv, 1);
	win.x = a;
	win.y = b;
	g_win(&win, 1);
}
