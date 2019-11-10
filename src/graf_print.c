/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graf_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:50:16 by lminta            #+#    #+#             */
/*   Updated: 2019/10/21 20:08:32 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		g_mod(int new_mod, int flag)
{
	static int	current_mod = 1;

	if (flag)
		current_mod = new_mod;
	return (current_mod);
}

int		g_help(int new_help, int flag)
{
	static int	current_mod = 0;

	if (flag)
		current_mod = new_help;
	return (current_mod);
}

t_color	g_end_c(t_color color, int flag)
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

void	draw_map(t_map *map)
{
	if (g_mod(0, 0) == 1)
		map_mod(map);
	if (g_mod(0, 0) == 2)
		mono_mod(map);
	if (g_mod(0, 0) == 3)
		pride_mod(map);
	if (g_mod(0, 0) == 4)
		grad_mod(map);
	if (g_mod(0, 0) == 5)
		fill_mod(map);
	print_text();
}
