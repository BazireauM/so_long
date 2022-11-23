/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:06:14 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 20:36:40 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	first_print(struct s_img *img, struct s_map *map, struct s_win *win)
{
	struct s_xy	xy;

	xy.y = 0;
	while (map->map[xy.y])
	{
		xy.x = 0;
		while (map->map[xy.y][xy.x] != '\n' && map->map[xy.y][xy.x])
		{
			display_choose(map->map[xy.y][xy.x], img, &xy, win);
			xy.x++;
		}
		xy.y++;
	}
	return (0);
}

void	display_choose(char c, struct s_img *img, struct s_xy *xy,
			struct s_win *win)
{
	if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->wall,
			xy->x * 20, xy->y * 20);
	else if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->none,
			xy->x * 20, xy->y * 20);
	else if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->item,
			xy->x * 20, xy->y * 20);
	else if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->door,
			xy->x * 20, xy->y * 20);
	else if (c == 'P')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->fox,
			xy->x * 20, xy->y * 20);
}
