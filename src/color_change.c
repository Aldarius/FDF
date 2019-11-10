/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:06:06 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 21:55:52 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	new_color(void)
{
	t_color col;

	col = fill_color(0, 0, 0);
	if (g_color(col, 0).r && g_color(col, 0).g && g_color(col, 0).b)
		g_color(fill_color(255, 0, 0), 1);
	else if (g_color(col, 0).r && !g_color(col, 0).g && !g_color(col, 0).b)
		g_color(fill_color(0, 255, 0), 1);
	else if (!g_color(col, 0).r && g_color(col, 0).g && !g_color(col, 0).b)
		g_color(fill_color(0, 0, 255), 1);
	else if (!g_color(col, 0).r && !g_color(col, 0).g && g_color(col, 0).b)
		g_color(fill_color(255, 255, 0), 1);
	else if (g_color(col, 0).r && g_color(col, 0).g && !g_color(col, 0).b)
		g_color(fill_color(255, 0, 255), 1);
	else if (g_color(col, 0).r && !g_color(col, 0).g && g_color(col, 0).b)
		g_color(fill_color(0, 255, 255), 1);
	else if (!g_color(col, 0).r && g_color(col, 0).g && g_color(col, 0).b)
		g_color(fill_color(0, 0, 0), 1);
	else if (!g_color(col, 0).r && !g_color(col, 0).g && !g_color(col, 0).b)
		g_color(fill_color(255, 255, 255), 1);
}

static void	end_color(void)
{
	t_color col;

	col = fill_color(0, 0, 0);
	if (g_end_c(col, 0).r && g_end_c(col, 0).g && g_end_c(col, 0).b)
		g_end_c(fill_color(255, 0, 0), 1);
	else if (g_end_c(col, 0).r && !g_end_c(col, 0).g && !g_end_c(col, 0).b)
		g_end_c(fill_color(0, 255, 0), 1);
	else if (!g_end_c(col, 0).r && g_end_c(col, 0).g && !g_end_c(col, 0).b)
		g_end_c(fill_color(0, 0, 255), 1);
	else if (!g_end_c(col, 0).r && !g_end_c(col, 0).g && g_end_c(col, 0).b)
		g_end_c(fill_color(255, 255, 0), 1);
	else if (g_end_c(col, 0).r && g_end_c(col, 0).g && !g_end_c(col, 0).b)
		g_end_c(fill_color(255, 0, 255), 1);
	else if (g_end_c(col, 0).r && !g_end_c(col, 0).g && g_end_c(col, 0).b)
		g_end_c(fill_color(0, 255, 255), 1);
	else if (!g_end_c(col, 0).r && g_end_c(col, 0).g && g_end_c(col, 0).b)
		g_end_c(fill_color(0, 0, 0), 1);
	else if (!g_end_c(col, 0).r && !g_end_c(col, 0).g && !g_end_c(col, 0).b)
		g_end_c(fill_color(255, 255, 255), 1);
}

void		change_color(int keycode)
{
	if (keycode == 18)
		g_mod(1, 1);
	else if (keycode == 19)
		g_mod(2, 1);
	else if (keycode == 20)
		g_mod(3, 1);
	else if (keycode == 21)
		g_mod(4, 1);
	else if (keycode == 23)
		g_mod(5, 1);
	else if (keycode == 43)
		new_color();
	else if (keycode == 47)
		end_color();
	else if (keycode == 4)
	{
		if (g_help(0, 0))
			g_help(0, 1);
		else
			g_help(1, 1);
	}
}

t_move		upside(int keycode)
{
	t_move	mv;

	mv = g_mv(0, 0);
	if (keycode == 32)
	{
		mv.alpha = 0;
		mv.beta = 0;
		mv.gamma = 0;
	}
	else
		change_color(keycode);
	return (mv);
}
