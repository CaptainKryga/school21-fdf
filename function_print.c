/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 09:28:22 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 10:47:51 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	out_map(t_window *win, t_pos ***map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < win->base->height)
	{
		while (x < win->base->width)
		{
			ft_printf("%*d", 3, map[y][x]->z);
			x++;
		}
		x = 0;
		y++;
		ft_printf("\n");
	}
	ft_printf("\n");
}
