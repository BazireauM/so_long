/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 02:29:57 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/24 18:37:18 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nb_item(struct s_all *all)
{
	int	i;
	int	b;

	i = 0;
	while (all->map.map[i])
	{
		b = 0;
		while (all->map.map[i][b])
		{
			if (all->map.map[i][b] == 'C')
				return (1);
			b++;
		}
		i++;
	}
	return (0);
}
