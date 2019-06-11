/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:24:26 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 10:49:13 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_pos *map, t_window *win)
{
	double	previous_y;
	double	previous_z;

	previous_y = map->y;
	previous_z = map->z;
	map->y = previous_y * cos(win->cyp->rot_x) + previous_z *
		sin(win->cyp->rot_x);
	map->z = -previous_y * sin(win->cyp->rot_x) + previous_z *
		cos(win->cyp->rot_x);
}

void		rotate_y(t_pos *map, t_window *win)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;

	previous_x = map->x;
	previous_y = map->x;
	previous_z = map->z;
	map->x = previous_x * cos(win->cyp->rot_y) + previous_z *
		sin(win->cyp->rot_y);
	map->z = -previous_y * sin(win->cyp->rot_y) + previous_z *
		cos(win->cyp->rot_y);
}

void		rotate_z(t_pos *map, t_window *win)
{
	double	previous_y;
	double	previous_x;

	previous_y = map->y;
	previous_x = map->x;
	map->x = previous_x * cos(win->cyp->rot_z) - previous_y *
		cos(win->cyp->rot_z);
	map->y = previous_x * sin(win->cyp->rot_z) + previous_y *
		cos(win->cyp->rot_z);
}

void		rotate_map(t_window *win)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < win->base->height)
	{
		while (x < win->base->width)
		{
			rotate_x(win->map[y][x], win);
			rotate_y(win->map[y][x], win);
			x++;
		}
		y++;
		x = 0;
	}
}
