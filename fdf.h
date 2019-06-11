/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:29:27 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 13:40:15 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "ft_printf.h"
# include "keycode.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define SIZEX 2000
# define SIZEY 1000
# define MALLOCHECK(x) if (!(x)) exit (0);

typedef struct				s_create_map
{
	char					**mas;
	char					**mas2;
	int						height;
	int						width;
	int						y;
	int						x;
}							t_create_map;

typedef struct				s_create_start_position
{
	int						max_y;
	int						min_y;
	int						max_x;
	int						min_x;
	int						x;
	int						y;
}							t_create_start_position;

typedef struct				s_check_map
{
	char					**split_y;
	char					**split_x;
	char					**split_d;
	int						i;
	int						z;
	int						err;
	int						err2;
	int						err3;
	int						x;
	int						y;
}							t_check_map;

typedef struct				s_pos
{
	int						x;
	int						y;
	int						z;
	int						flag;
	int						colour;
}							t_pos;

typedef struct				s_base
{
	int						width;
	int						height;
	int						depth;
	int						start_x;
	int						start_y;
	int						step;
	int						flag_null;
}							t_base;

typedef struct				s_cyp
{
	int						type_iso;
	int						run_x;
	int						run_y;
	int						run_z;
	int						zoom;
	int						save_zoom;
	double					rot_x;
	double					rot_y;
	double					rot_z;
	int						colour_swap;
	int						colour_black;
	int						flag_paint;
	int						war;
}							t_cyp;

typedef struct				s_window
{
	void					*mlx;
	void					*win;
	int						width;
	int						height;
	t_pos					***map;
	t_pos					***copy_map;
	t_base					*base;
	t_cyp					*cyp;
}							t_window;
t_create_start_position		*create_start_position(void);
void						start_position(t_window *win);
void						start_position_two(t_window *win,\
								t_create_start_position *var);
void						while_line(t_window *win);
int							check_colour(char *str, int *i);
int							map_check(char *map, char *file);
void						map_check_mini(const char *map, char *file);
void						check_map_one(t_check_map *var, char *file);
void						check_map_two(t_check_map *var, char *file);
void						fdf(t_window *win);
t_pos						***copy_map(t_window *win);
void						restart_map(t_window *win, int flag_colour);
void						while_line(t_window *win);
int							main(int argc, char **argv);
t_window					*inicialization_win();
int							create_width(const char *map);
int							create_height(const char *map);
void						rainbow(t_window *win);
char						*ft_parser(int fd, ssize_t x);
char						*ft_preparser(char *file);
void						mister_brezent(t_window *win,\
								t_pos dot1, t_pos dot2);
void						iso_map(t_window *win);
void						iso(t_pos *map);
void						iso2(t_pos *map);
void						iso3(t_pos *map);
void						iso4(t_pos *map);
void						zoom(t_window *win);
void						run(t_window *win);
void						start_position(t_window *win);
void						rotate_map(t_window *win);
t_base						*create_base(char *map);
t_pos						***create_map(t_window *win, char *str);
t_cyp						*create_cyp();
t_check_map					*create_check_map();
int							map_check(char *map, char *file);
void						televisor(t_window *win, int flag, int flag_colour);
void						out_map(t_window *win, t_pos ***map);
void						cosmos(t_window *win);
void						center(t_window *win);
void						controls(t_window *win);
int							key_press(int key, void *fdf);
int							get_colour(t_pos current,\
								t_pos start, t_pos end, t_pos delta);
void						iso(t_pos *map);
void						iso2(t_pos *map);
void						iso3(t_pos *map);
void						iso4(t_pos *map);
void						rotate_map(t_window *win);
void						rotate_x(t_pos *map, t_window *win);
void						rotate_y(t_pos *map, t_window *win);
t_create_map				*create_var_map(void);
void						menu(t_window *win);
void						key_move(int key, t_window *win);
void						key_centr(int key, t_window *win);
void						key_iso1(int key, t_window *win);
void						key_iso2(int key, t_window *win);
void						key_iso3(int key, t_window *win);
void						key_iso4(int key, t_window *win);
void						key_z(int key, t_window *win);
void						key_zoom(int key, t_window *win);
void						key_rotate(int key, t_window *win);
void						key_colour(int key, t_window *win);
void						key_menu(int key, t_window *win);
int							expose(void *param);
void						key_colour_two(int key, t_window *win);

#endif
