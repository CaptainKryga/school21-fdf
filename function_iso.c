/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:22:26 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/08 11:22:29 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(t_pos *map)
{
	double	previous_x;
	double	previous_y;

	previous_x = map->x;
	previous_y = map->y;
	map->x = (previous_x - previous_y) * cos(0.523599);
	map->y = -map->z + (previous_x + previous_y) * sin(0.523599);
}

void		iso2(t_pos *map)
{
	double	previous_x;
	double	previous_y;

	previous_x = map->x;
	previous_y = map->y;
	map->x = (previous_x + previous_y) * cos(0.523599);
	map->y = (previous_x - previous_y) * sin(0.523599) - map->z;
}

void		iso3(t_pos *map)
{
	double	previous_x;
	double	previous_y;

	previous_x = map->x;
	previous_y = map->y;
	map->x = (previous_x - previous_y) * -cos(0.523599);
	map->y = ((previous_x + previous_y) * sin(0.523599)) - map->z;
}

void		iso4(t_pos *map)
{
	double	previous_x;
	double	previous_y;

	previous_x = map->x;
	previous_y = map->y;
	map->x = (previous_x + previous_y) * -cos(0.523599);
	map->y = ((previous_x - previous_y) * sin(0.523599)) - map->z;
}

void		iso_map(t_window *win)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < win->base->height)
	{
		while (x < win->base->width)
		{
			win->map[y][x]->y = win->map[y][x]->y;
			win->map[y][x]->x = win->map[y][x]->x;
			if (win->cyp->type_iso == 1)
				iso(win->map[y][x]);
			else if (win->cyp->type_iso == 2)
				iso2(win->map[y][x]);
			else if (win->cyp->type_iso == 3)
				iso3(win->map[y][x]);
			else if (win->cyp->type_iso == 4)
				iso4(win->map[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
}
