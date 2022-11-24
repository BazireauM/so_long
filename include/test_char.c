/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:06:59 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/24 20:22:53 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_char(struct s_map *map)
{
	if (test_char_p(map) == 1 || test_char_e(map) == 1 || test_char_c(map) == 1)
		return (1);
	return (0);
}

int	test_char_p(struct s_map *map)
{
	int	i;
	int	b;
	int	test;

	i = 0;
	test = 0;
	while (map->map[i])
	{
		b = 0;
		while (map->map[i][b])
		{
			if (map->map[i][b] == 'P')
				test++;
			b++;
		}
		i++;
	}
	if (test != 1)
		return (1);
	return (0);
}

int	test_char_e(struct s_map *map)
{
	int	i;
	int	b;
	int	test;

	i = 0;
	test = 0;
	while (map->map[i])
	{
		b = 0;
		while (map->map[i][b])
		{
			if (map->map[i][b] == 'E')
				test++;
			b++;
		}
		i++;
	}
	if (test != 1)
		return (1);
	return (0);
}

int	test_char_c(struct s_map *map)
{
	int	i;
	int	b;
	int	test;

	i = 0;
	test = 0;
	while (map->map[i])
	{
		b = 0;
		while (map->map[i][b])
		{
			if (map->map[i][b] == 'C')
				test++;
			b++;
		}
		i++;
	}
	if (test < 1)
		return (1);
	return (0);
}
