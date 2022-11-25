/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:39:43 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 02:21:50 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_way(struct s_map *map)
{
	int		i;
	char	**map_cp;

	map_cp = cpy_map(map);
	map_cp = init_shearch_way(map_cp);
	i = 0;
	while (i == 1)
	{
		//i = search_way(map_cp);
	}
	// if count_E_and_C == 0 return (0) else return (1)
	return (0);
}

int	search_way(char **map_cp)
{
	int	i;
	int	b;

	i = 0;
	while (map_cp[i])
	{
		b = 0;
		while (map_cp[i][b])
		{
			if (test_new_case(map_cp, i, b) == 1)
				return (1);
			b++;
		}
		i++;
	}
	return (0);
}

int test_new_case(char **map_cp, int i, int b)
{
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

char	**init_shearch_way(char **map_cp)
{
	int	i;
	int	b;

	i = 0;
	while (map[i])
	{
		b = 0;
		while (map[i][b])
		{
			if (map[i][b] == 'P')
				map[i][b] = '3';
			b++;
		}
		i++;
	}
	return (map_cp);
}
