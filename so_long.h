/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:20:09 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/24 04:39:43 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

struct	s_map
{
	int		lenx;
	int		leny;
	char	**map;
}	t_map;

struct	s_img
{
	void	*wall;
	void	*fox;
	void	*none;
	void	*item;
	void	*door;
	int		x;
	int		y;
}	t_img;

struct	s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_win;

struct s_xy
{
	int	x;
	int	y;
}	t_xy;

struct s_all
{
	struct s_win	win;
	struct s_img	img;
	struct s_map	map;
}	t_all;

char		**parssing_map(char *map);
char		**append_final(char **final, char *tmp);
int			len_char_char(char **final);
int			free_all_final(char **final);
int			first_print(struct s_img *img, struct s_map *map,
				struct s_win *win);
void		init_img(struct s_img *img, struct s_win *win);
void		display_choose(char c, struct s_img *img, struct s_xy *xy,
				struct s_win *win);
int			mov_left(struct s_all *all);
int			mov_right(struct s_all *all);
int			mov_up(struct s_all *all);
int			mov_down(struct s_all *all);
struct s_xy	search_pos(struct s_all *all);
int			nb_item(struct s_all *all);

#endif
