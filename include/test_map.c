/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:17:28 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 03:37:48 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_map(struct s_map *map)
{
	//carte rectangle
	if (rectangle(map) == 1)
		return (1);
	//carte ferme
	if (surrounded(map) == 1)
		return (1);
	//test 1 sortie, au moin 1 item, 1 position de depart
	if (test_char(map) == 1)
		return (1);
	//chemin possible
	if (test_way(map) == 1)
		return (1);
	return (0);
}

int	rectangle(struct s_map *map)
{
	int	i;
	int	len;

	len = ft_strlen(map->map[0]);
	i = 1;
	while (map->map[i + 1])
	{
		if ((int)ft_strlen(map->map[i]) != len)
			return (1);
		i++;
	}
	if ((int)ft_strlen(map->map[i]) != len - 1)
		return (1);
	i++;
	map->lenx = len - 1;
	map->leny = i;
	return (0);
}

int	surrounded(struct s_map *map)
{
	int	i;

	i = 0;
	while (i < map->lenx - 1)
	{
		if (map->map[0][i] != '1')
		{
			return (1);
		}
		if (map->map[map->leny - 1][i] != '1')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map->leny - 1)
	{
		if (map->map[i][0] != '1')
			return (1);
		if (map->map[i][map->lenx - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
