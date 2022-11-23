/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:20:09 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 19:42:24 by mbazirea         ###   ########.fr       */
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
	int x;
	int y;
}	s_xy;

char			**parssing_map(char *map);
char			**append_final(char **final, char *tmp);
int				len_char_char(char **final);
int				free_all_final(char **final);
int				first_print(struct s_img *img, struct s_map *map,
					struct s_win *win);
struct s_img	init_img(struct s_img *img, struct s_win *win);
void			display_choose(char c, struct s_img *img, struct s_xy *xy,
					struct s_win *win);

#endif
