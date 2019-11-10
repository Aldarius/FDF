/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:58:22 by lminta            #+#    #+#             */
/*   Updated: 2019/06/11 20:10:10 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_line.h"

t_matrix	*turn_move(t_matrix *point)
{
	t_matrix	*res;

	if (!point)
		return (0);
	point->map[2][0] *= g_mv(0, 0).contrast;
	if (!(res = proection(mult_matrix(turn_z_matrix(g_mv(0, 0).gamma),
	mult_matrix(turn_y_matrix(g_mv(0, 0).beta),
	mult_matrix(turn_x_matrix(g_mv(0, 0).alpha), point))))))
		return (0);
	res->map[0][0] = res->map[0][0] * g_mv(0, 0).zoom + g_mv(0, 0).rl;
	res->map[1][0] = res->map[1][0] * g_mv(0, 0).zoom + g_mv(0, 0).ud;
	return (res);
}

void		draw_vector(t_matrix *point1, t_matrix *point2,
t_color col1, t_color col2)
{
	t_xy	p1;
	t_xy	p2;

	if (!point1 || !point2)
		return ;
	if (!(point1 = turn_move(point1)))
		return ;
	if (!(point2 = turn_move(point2)))
		return ;
	p1.x = point1->map[0][0];
	p1.y = point1->map[1][0];
	p2.x = point2->map[0][0];
	p2.y = point2->map[1][0];
	p1.color = col1;
	p2.color = col2;
	clip(p1, p2);
	del_matrix(point1);
	del_matrix(point2);
}

void		ft_swap_color(t_color *a, t_color *b)
{
	t_color buff;

	buff = *a;
	*a = *b;
	*b = buff;
}

int			rgb_to_int(t_color cl)
{
	int	rgb;

	rgb = ((int)(cl.r) << 16) + ((int)(cl.g) << 8)
	+ (int)(cl.b);
	return (rgb);
}
