/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_fill2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:53:18 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:00:24 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_line.h"

t_mlx		g_mlx(t_mlx *mlx, int flag)
{
	static t_mlx	gmlx;

	if (flag)
	{
		gmlx = *mlx;
		return (gmlx);
	}
	else
		return (gmlx);
}

t_xy		g_win(t_xy *win, int flag)
{
	static t_xy	gwin;

	if (flag)
	{
		gwin = *win;
		return (gwin);
	}
	else
		return (gwin);
}

void		img_plot(int x, int y, t_color cl)
{
	int		i;
	t_mlx	mlx;

	mlx = g_mlx(0, 0);
	i = x * mlx.bits_per_pixel / 8 + y * mlx.size_line;
	mlx.image[i++] = (int)(cl.b * cl.br);
	mlx.image[i++] = (int)(cl.g * cl.br);
	mlx.image[i] = (int)(cl.r * cl.br);
	g_mlx(&mlx, 1);
}

void		plot(int x, int y, t_color cl)
{
	int		rgb;

	rgb = ((int)(cl.r * cl.br) << 16) + ((int)(cl.g * cl.br) << 8)
	+ (int)(cl.b * cl.br);
	if (rgb)
		mlx_pixel_put(g_mlx(0, 0).mlx_ptr,
		g_mlx(0, 0).win_ptr, x, y, (int)(rgb));
}

t_color		int_to_rgb(int rgb)
{
	t_color	col;

	col = fill_color(0, 0, 0);
	if (rgb == -1)
		return (g_color(col, 0));
	col.br = 1;
	col.b = rgb & 255;
	col.g = (rgb >> 8) & 255;
	col.r = (rgb >> 16) & 255;
	return (col);
}
