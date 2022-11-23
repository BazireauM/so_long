/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:08:23 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 03:12:30 by mbazirea         ###   ########.fr       */
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
	/*
	void	*test;
	void	*init;
	void	*image;
	int		x;
	int		y;

	x = 20;
	y = 20;
	*/
	char	**map;
	int		i;
	printf("%s\n", argv[1]);
	map = parssing_map(argv[1]);
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
	argc++;
	/*
	init = mlx_init();
	test = mlx_new_window(init, 500, 500, "test");
	image = mlx_new_image(init, 20, 20);
	image = mlx_xpm_file_to_image(init, "sprite/Wall.xpm", &x, &y);
	mlx_put_image_to_window(init, test, image, 50, 50);
	mlx_put_image_to_window(init, test, image, 100, 100);
	mlx_key_hook(test, deal_key, (void *)0);
	mlx_loop(init);
	*/
}
