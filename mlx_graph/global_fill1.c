/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_fill1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:20:10 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:04:58 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_line.h"

t_move		g_mv(t_move *mv, int flag)
{
	static t_move	gmv;
	static t_move	start_mv;

	if (flag == 1)
		gmv = *mv;
	if (flag == 2)
		gmv = start_mv;
	if (flag == 3)
	{
		start_mv = *mv;
		gmv = start_mv;
	}
	return (gmv);
}

t_color		fill_color(double red, double green, double blue)
{
	t_color color;

	if (red < 0)
		color.r = 0;
	else if (red > 255)
		color.r = 255;
	else
		color.r = red;
	if (green < 0)
		color.g = 0;
	else if (green > 255)
		color.g = 255;
	else
		color.g = green;
	if (blue < 0)
		color.b = 0;
	else if (blue > 255)
		color.b = 255;
	else
		color.b = blue;
	return (color);
}

t_color		g_color(t_color color, int flag)
{
	static t_color	gcolor;

	if (flag)
	{
		gcolor = color;
		return (gcolor);
	}
	else
		return (gcolor);
}

t_borders	fill_borders(double xmin, double ymin, double xmax, double ymax)
{
	t_borders borders;

	borders.xmin = xmin;
	borders.ymin = ymin;
	borders.xmax = xmax;
	borders.ymax = ymax;
	return (borders);
}

t_borders	g_borders(t_borders borders, int flag)
{
	static t_borders	gborders;

	if (flag)
	{
		gborders = borders;
		return (gborders);
	}
	else
		return (gborders);
}
