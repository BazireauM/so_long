/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_way_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:27:02 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 03:37:50 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_e_and_c(char **map_cp)
{
	int	i;
	int	b;

	i = 0;
	while (map_cp[i])
	{
		b = 0;
		while (map_cp[i][b])
		{
			if (map_cp[i][b] == 'E' || map_cp[i][b] == 'C')
				return (1);
			b++;
		}
		i++;
	}
	return (0);
}
