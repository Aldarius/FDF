/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:23:57 by lminta            #+#    #+#             */
/*   Updated: 2019/06/09 17:07:47 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void		del_matrix(t_matrix *mat)
{
	int		i;

	if (!mat)
		return ;
	i = 0;
	while (i < mat->l)
	{
		free(mat->map[i]);
		i++;
	}
	free(mat->map);
	free(mat);
}

void		zero_matrix(t_matrix *mat)
{
	int		i;
	int		j;

	if (!mat)
		return ;
	i = 0;
	while (i < mat->l)
	{
		j = 0;
		while (j < mat->m)
		{
			mat->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_matrix	*dub_matrix(t_matrix *mat)
{
	int			i;
	int			j;
	t_matrix	*res;

	if (!mat || !(res = create_matrix(mat->l, mat->m)))
		return (0);
	i = 0;
	while (i < mat->l)
	{
		j = 0;
		while (j < mat->m)
		{
			res->map[i][j] = mat->map[i][j];
			j++;
		}
		i++;
	}
	return (res);
}
