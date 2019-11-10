/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:14:19 by lminta            #+#    #+#             */
/*   Updated: 2019/06/06 21:15:53 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*create_matrix(int l, int m)
{
	t_matrix	*res;
	int			i;

	i = 0;
	if (!(res = (t_matrix *)malloc(sizeof(t_matrix))))
		return (0);
	res->l = l;
	res->m = m;
	if (!(res->map = (double **)malloc(sizeof(double *) * l)))
		return (0);
	while (i < l)
	{
		if (!(res->map[i] = (double *)malloc(sizeof(double) * m)))
		{
			res->l = i;
			del_matrix(res);
			return (0);
		}
		i++;
	}
	zero_matrix(res);
	return (res);
}

t_matrix	*turn_x_matrix(double alpha)
{
	t_matrix	*res;

	if (!(res = create_matrix(3, 3)))
		return (0);
	res->map[0][0] = 1;
	res->map[1][1] = cos(alpha);
	res->map[2][2] = cos(alpha);
	res->map[2][1] = sin(alpha);
	res->map[1][2] = -sin(alpha);
	return (res);
}

t_matrix	*turn_y_matrix(double beta)
{
	t_matrix	*res;

	if (!(res = create_matrix(3, 3)))
		return (0);
	res->map[1][1] = 1;
	res->map[0][0] = cos(beta);
	res->map[2][2] = cos(beta);
	res->map[0][2] = sin(beta);
	res->map[2][0] = -sin(beta);
	return (res);
}

t_matrix	*turn_z_matrix(double gamma)
{
	t_matrix	*res;

	if (!(res = create_matrix(3, 3)))
		return (0);
	res->map[2][2] = 1;
	res->map[0][0] = cos(gamma);
	res->map[1][1] = cos(gamma);
	res->map[1][0] = sin(gamma);
	res->map[0][1] = -sin(gamma);
	return (res);
}

t_matrix	*create_vector(double x, double y, double z)
{
	t_matrix	*res;

	if (!(res = create_matrix(3, 1)))
		return (0);
	res->map[0][0] = x;
	res->map[1][0] = y;
	res->map[2][0] = z;
	return (res);
}
