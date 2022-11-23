/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:06:14 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 19:42:18 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	first_print(struct s_img *img, struct s_map *map, struct s_win *win)
{
	struct s_xy xy;

	xy.y = 0;
	while (map->map[xy.y])
	{
		xy.x = 0;
		while (map->map[xy.y][xy.x] != '\n' && map->map[xy.y][xy.x])
		{
			printf("%c\n", map->map[xy.y][xy.x]);
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
	{
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->wall , xy->y * 20, xy->x * 20);
	}
	else if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->none,
				xy->y * 20, xy->x * 20);
	else if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->item,
				xy->y * 20, xy->x * 20);
	else if (c == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->door,
				xy->y * 20, xy->x * 20);
	else if (c == 'P')
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, img->fox,
				xy->y * 20, xy->x * 20);
}

void	init_img(struct s_img *img, struct s_win *win)
{
	img->wall = mlx_new_image(win->mlx_ptr, img->x, img->y);
	img->fox = mlx_new_image(win->mlx_ptr, img->x, img->y);
	img->none = mlx_new_image(win->mlx_ptr, img->x, img->y);
	img->item = mlx_new_image(win->mlx_ptr, img->x, img->y);
	img->door = mlx_new_image(win->mlx_ptr, img->x, img->y);
	img->wall = mlx_xpm_file_to_image(win->mlx_ptr, "../sprite/Wall.xpm",
			&(img->x), &(img->y));
	img->fox = mlx_xpm_file_to_image(win->mlx_ptr, "../sprite/Fox.xpm",
			&img->x, &img->y);
	img->item = mlx_xpm_file_to_image(win->mlx_ptr, "../sprite/item.xpm",
			&img->x, &img->y);
	img->door = mlx_xpm_file_to_image(win->mlx_ptr, "../sprite/Door.xpm",
			&img->x, &img->y);
	img->none = mlx_xpm_file_to_image(win->mlx_ptr, "../sprite/none.xpm",
			&img->x, &img->y);
	printf("%p\n%p\n", &img->x, &img->y);
}
