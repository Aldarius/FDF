/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:33:52 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:05:43 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_LINE_H
# define FT_DRAW_LINE_H

# include "mlx.h"
# include "matrix.h"
# include <math.h>
# include <stdlib.h>

typedef struct	s_move
{
	double		ud;
	double		rl;
	double		zoom;
	double		contrast;
	double		alpha;
	double		beta;
	double		gamma;
}				t_move;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	double		br;
}				t_color;

typedef struct	s_xy
{
	double		x;
	double		y;
	double		intery;
	t_color		color;
}				t_xy;

typedef struct	s_borders
{
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;

}				t_borders;

typedef struct	s_steep_grad
{
	int			steep;
	double		grad;
}				t_steep_grad;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*image;
}				t_mlx;

void			draw_line(t_xy xy0, t_xy xy1);
void			plot(int x, int y, t_color cl);
void			ft_mlx_init(int a, int b, char *str);
int				ipart(double x);
int				ft_round(double x);
double			fpart(double x);
double			rfpart(double x);
void			ft_swap(double *a, double *b);
t_color			fill_color(double red, double green, double blue);
void			clip(t_xy xy1, t_xy xy2);
t_borders		fill_borders(double xmin,
double ymin, double xmax, double ymax);
t_borders		g_borders(t_borders borders, int flag);
t_color			g_color(t_color color, int flag);
t_move			g_mv(t_move *mv, int flag);
t_matrix		*turn_move(t_matrix *vector);
void			draw_vector(t_matrix *point1, t_matrix *point2,
t_color col1, t_color col2);
t_mlx			g_mlx(t_mlx *mlx, int flag);
t_xy			g_win(t_xy *win, int flag);
t_color			int_to_rgb(int rgb);
t_color			gradient(t_color color1, t_color color2, double length);
t_color			sum_collors(t_color color, t_color grad, int count);
void			ft_swap_color(t_color *a, t_color *b);
int				rgb_to_int(t_color cl);

#endif
