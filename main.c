/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:08:23 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 21:16:26 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, struct s_all *all)
{
	char	c;

	if (key == 13)
		mov_up(all);
	else if (key == 2)
		mov_right(all);
	else if (key == 1)
		mov_down(all);
	else if (key == 0)
		mov_left(all);
	else if (key == 53)
		exit(1);
	write(1, &c, 1);
	return (0);
}

int	ft_exit(struct s_all *all)
{
	printf("test\n");
	all->map.map[0][0] = '1';
	exit(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	struct s_win	win;
	struct s_img	img;
	struct s_map	map;
	struct s_all	all;
	int				i;

	img.x = 20;
	img.y = 20;
	if (argc != 2)
		return (0);
	if (test_file(argv[1]) == 1)
	{
		ft_printf("error files\n");
		return (0);
	}
	printf("%s\n", argv[1]);
	map.map = parssing_map(argv[1]);
	i = 0;
	while (map.map[i])
	{
		printf("%s", map.map[i]);
		i++;
	}
	printf("\n");
	if (test_map(&map) != 1)
	{
		win.mlx_ptr = mlx_init();
		win.mlx_win = mlx_new_window(win.mlx_ptr, map.lenx * 20,
				map.leny * 20, "so long");
		init_img(&img, &win);
		first_print(&img, &map, &win);
		all.win = win;
		all.img = img;
		all.map = map;
		mlx_key_hook(win.mlx_win, deal_key, &all);
		mlx_hook(win.mlx_win, 17, 0L, ft_exit, &all);
		mlx_loop(win.mlx_ptr);
	}
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
