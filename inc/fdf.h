/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:55:43 by lminta            #+#    #+#             */
/*   Updated: 2019/10/21 20:08:00 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_draw_line.h"
# include "get_next_line.h"
# include "fillit.h"
# include <stdio.h>
# include <errno.h>

typedef struct	s_point
{
	int			z;
	int			color;
}				t_point;

typedef struct	s_map
{
	t_point		**map;
	int			size_h;
	int			size_w;
	int			min;
	int			max;
}				t_map;

int				map_clean(t_map *map);
int				map_size(t_map *map, int fd);
void			parse(t_map *map, char *line);
t_map			*read_map(char *fname);
void			draw_map(t_map *map);
int				g_mod(int new_mod, int flag);
void			change_color(int keycode);
t_color			g_end_c(t_color color, int flag);
void			map_mod(t_map *map);
void			pride_mod(t_map *map);
void			mono_mod(t_map *map);
void			grad_mod(t_map *map);
void			print_text(void);
void			print_help(void);
int				g_help(int new_help, int flag);
t_move			upside(int keycode);
int				press_x(t_map *map);
t_map			*fill_my_fdf(char *fname);
int				field_create(t_map *map);
int				create_map(t_map **map);
void			fill_mod(t_map *map);
int				cam_fdf(int keycode, t_map *map);

#endif
