/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:08:23 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 20:36:56 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, void *param)
{
	char	c;

	if (key == 13)
		c = 'w';
	else if (key == 2)
		c = 'd';
	else if (key == 1)
		c = 's';
	else if (key == 0)
		c = 'a';
	else if (key == 53)
		c = 'e';
	write(1, &c, 1);
	return (0);
	printf("\n%p\n", param);
	printf("%d\n", key);
	return (0);
}

int	main(int argc, char *argv[])
{
	struct s_win	win;
	struct s_img	img;
	struct s_map	map;
	int				i;

	img.x = 20;
	img.y = 20;
	printf("%s\n", argv[1]);
	map.map = parssing_map(argv[1]);
	i = 0;
	while (map.map[i])
	{
		printf("%s", map.map[i]);
		i++;
	}
	printf("\n");
	argc++;
	win.mlx_ptr = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx_ptr, 1000, 1000, "test");
	init_img(&img, &win);
	first_print(&img, &map, &win);
	mlx_key_hook(win.mlx_win, deal_key, (void *)0);
	mlx_loop(win.mlx_ptr);
}

void	init_img(struct s_img *img, struct s_win *win)
{
	img->wall = mlx_new_image(win->mlx_ptr, 20, 20);
	img->fox = mlx_new_image(win->mlx_ptr, 20, 20);
	img->none = mlx_new_image(win->mlx_ptr, 20, 20);
	img->item = mlx_new_image(win->mlx_ptr, 20, 20);
	img->door = mlx_new_image(win->mlx_ptr, 20, 20);
	img->wall = mlx_xpm_file_to_image(win->mlx_ptr, "sprite/Wall.xpm",
			&img->x, &img->y);
	img->fox = mlx_xpm_file_to_image(win->mlx_ptr, "sprite/Fox.xpm",
			&img->x, &img->y);
	img->item = mlx_xpm_file_to_image(win->mlx_ptr, "sprite/item.xpm",
			&img->x, &img->y);
	img->door = mlx_xpm_file_to_image(win->mlx_ptr, "sprite/Door.xpm",
			&img->x, &img->y);
	img->none = mlx_xpm_file_to_image(win->mlx_ptr, "sprite/none.xpm",
			&img->x, &img->y);
}
