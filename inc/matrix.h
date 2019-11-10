/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:49:49 by lminta            #+#    #+#             */
/*   Updated: 2019/06/11 17:58:17 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_matrix
{
	double		**map;
	int			l;
	int			m;
}				t_matrix;

void			del_matrix(t_matrix *mat);
void			zero_matrix(t_matrix *mat);

t_matrix		*create_matrix(int l, int m);
t_matrix		*create_vector(double x, double y, double z);

t_matrix		*turn_x_matrix(double alpha);
t_matrix		*turn_y_matrix(double beta);
t_matrix		*turn_z_matrix(double gamma);
t_matrix		*mult_matrix(t_matrix *a, t_matrix *b);
t_matrix		*dub_matrix(t_matrix *mat);
t_matrix		*proection(t_matrix	*vector);

#endif
