/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:08:23 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 17:25:38 by mbazirea         ###   ########.fr       */
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

int	main(int argc,char *argv[])
{
	struct	s_win	win;
	struct	s_img	img;
	struct s_map	map;
	int		i;
	int		x;
	int		y;

	x = 20;
	y = 20;
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
	win.mlx_win = mlx_new_window(win.mlx_ptr, 500, 500, "test");
	img.fox = mlx_new_image(win.mlx_ptr, 20, 20);
	img.fox = mlx_xpm_file_to_image(win.mlx_ptr, "sprite/Fox.xpm", &x, &y);
	mlx_put_image_to_window(win.mlx_ptr, win.mlx_win, img.fox, 0, 0);
	//first_print(map);
	mlx_key_hook(win.mlx_win, deal_key, (void *)0);
	mlx_loop(win.mlx_ptr);
}
