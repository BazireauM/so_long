/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:39:43 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 02:03:47 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_way(struct s_map *map)
{
	int		i;
	char	**map_cp;

	map_cp = cpy_map(map);
	i = 0;
	while (i == 1)
	{
		//i = search_way(map_cp);
	}
	return (0);
}

char	**cpy_map(struct s_map *map)
{
	char	**map_cp;
	int		i;
	int		b;

	map_cp = malloc(sizeof(char *) * (map->leny + 1));
	if (!map_cp)
		return (NULL);
	i = 0;
	while (map->map[i])
	{
		map_cp[i] = malloc(sizeof(char *) * (ft_strlen(map->map[i]) + 1));
		b = 0;
		while (map->map[i][b])
		{
			map_cp[i][b] = map->map[i][b];
			b++;
		}
		map_cp[i][b] = '\0';
		i++;
	}
	map_cp[i] = NULL;
	return (map_cp);
}
