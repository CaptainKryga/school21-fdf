/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_malloc_structure.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:22:51 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 11:43:41 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_base			*create_base(char *map)
{
	t_base *base;

	MALLOCHECK(base = (t_base*)malloc(sizeof(t_base)));
	base->width = create_width(map);
	base->height = create_height(map);
	base->step = 51;
	base->depth = 4;
	base->start_x = 0;
	base->start_y = 0;
	base->flag_null = 0;
	return (base);
}

t_cyp			*create_cyp(void)
{
	t_cyp *cyp;

	MALLOCHECK(cyp = (t_cyp*)malloc(sizeof(t_cyp)));
	cyp->type_iso = 0;
	cyp->run_x = 0;
	cyp->run_y = 0;
	cyp->run_z = 1;
	cyp->zoom = 0;
	cyp->save_zoom = 0;
	cyp->rot_x = 0;
	cyp->rot_y = 0;
	cyp->rot_z = 0;
	cyp->colour_swap = 0x05FFB7;
	cyp->colour_black = 0x0;
	cyp->flag_paint = 0;
	cyp->war = 0;
	return (cyp);
}

t_window		*inicialization_win(void)
{
	t_window *win;

	MALLOCHECK(win = (t_window*)malloc(sizeof(t_window)));
	win->width = SIZEX;
	win->height = SIZEY;
	win->mlx = mlx_init();
	win->win = NULL;
	win->base = NULL;
	win->map = NULL;
	win->copy_map = NULL;
	win->cyp = NULL;
	return (win);
}

t_check_map		*create_check_map(void)
{
	t_check_map *check;

	MALLOCHECK(check = (t_check_map*)malloc(sizeof(t_check_map)));
	check->split_y = NULL;
	check->split_x = NULL;
	check->split_d = NULL;
	check->i = 0;
	check->z = 0;
	check->x = 0;
	check->y = 0;
	check->err = 0;
	check->err2 = 0;
	check->err3 = 0;
	return (check);
}

t_create_map	*create_var_map(void)
{
	t_create_map *map;

	MALLOCHECK(map = (t_create_map*)malloc(sizeof(t_create_map)));
	map->mas = NULL;
	map->mas2 = NULL;
	map->height = 0;
	map->width = 0;
	map->y = 0;
	map->x = 0;
	return (map);
}
