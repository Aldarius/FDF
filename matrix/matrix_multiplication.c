/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:13:56 by lminta            #+#    #+#             */
/*   Updated: 2019/06/09 17:07:47 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*mult_matrix(t_matrix *a, t_matrix *b)
{
	int			i;
	int			j;
	int			r;
	double		sum;
	t_matrix	*res;

	if (!a || !b || a->m != b->l)
		return (0);
	if (!(res = create_matrix(a->l, b->m)))
		return (0);
	i = -1;
	while (++i < a->l && (j = -1))
		while (++j < b->m && (r = -1))
		{
			sum = 0;
			while (++r < a->m)
				sum += a->map[i][r] * b->map[r][j];
			res->map[i][j] = sum;
		}
	del_matrix(a);
	del_matrix(b);
	return (res);
}

t_matrix	*proection(t_matrix *vector)
{
	t_matrix	*res;
	t_matrix	*buff;

	if (!vector || !(buff = create_matrix(3, 3)))
		return (0);
	buff->map[0][0] = 1;
	buff->map[1][1] = 1;
	if (!(res = mult_matrix(buff, vector)))
		return (0);
	return (res);
}
