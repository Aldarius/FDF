/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_koen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 20:42:51 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:07:31 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_line.h"

static int	code(t_borders bd, t_xy xy)
{
	return ((xy.x < bd.xmin) << 3 | (xy.x > bd.xmax) << 2 |
	(xy.y < bd.ymin) << 1 | (xy.y > bd.ymax));
}

static int	new_point(t_borders bd, t_xy *xy, t_xy dxy)
{
	if (xy->x < bd.xmin)
	{
		xy->y += dxy.y * (bd.xmin - xy->x) / dxy.x;
		xy->x = bd.xmin;
	}
	else if (xy->x > bd.xmax)
	{
		xy->y += dxy.y * (bd.xmax - xy->x) / dxy.x;
		xy->x = bd.xmax;
	}
	else if (xy->y < bd.ymin)
	{
		xy->x += dxy.x * (bd.ymin - xy->y) / dxy.y;
		xy->y = bd.ymin;
	}
	else if (xy->y > bd.ymax)
	{
		xy->x += dxy.x * (bd.ymax - xy->y) / dxy.y;
		xy->y = bd.ymax;
	}
	return (code(bd, *xy));
}

void		clip(t_xy xy1, t_xy xy2)
{
	int			c1;
	int			c2;
	t_xy		dxy;
	t_borders	bd;

	bd = fill_borders(0, 0, 0, 0);
	c1 = code(g_borders(bd, 0), xy1);
	c2 = code(g_borders(bd, 0), xy2);
	while (c1 | c2)
	{
		if (c1 & c2)
			return ;
		dxy.x = xy2.x - xy1.x;
		dxy.y = xy2.y - xy1.y;
		if (c1)
			c1 = new_point(g_borders(bd, 0), &xy1, dxy);
		else
			c2 = new_point(g_borders(bd, 0), &xy2, dxy);
	}
	draw_line(xy1, xy2);
}

t_color		gradient(t_color color1, t_color color2, double length)
{
	t_color	grad;

	if (!length)
		return (color2);
	grad.r = (color2.r - color1.r) / length;
	grad.g = (color2.g - color1.g) / length;
	grad.b = (color2.b - color1.b) / length;
	grad.br = 1;
	return (grad);
}

t_color		sum_collors(t_color color, t_color grad, int count)
{
	t_color	result;

	result.r = color.r + grad.r * count;
	result.g = color.g + grad.g * count;
	result.b = color.b + grad.b * count;
	result.br = color.br;
	return (result);
}
