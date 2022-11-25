/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:32:00 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/25 02:21:52 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mov_left(struct s_all *all)
{
	struct s_xy	pos;

	pos = search_pos(all);
	if (all->map.map[pos.y][pos.x - 1] != '1' &&
		all->map.map[pos.y][pos.x - 1] != 'E')
	{
		all->map.map[pos.y][pos.x - 1] = 'P';
		all->map.map[pos.y][pos.x] = '0';
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.none, pos.x * 20, pos.y * 20);
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.fox, (pos.x - 1) * 20, pos.y * 20);
	}
	if (all->map.map[pos.y][pos.x - 1] == 'E' && nb_item(all) == 0)
		exit(1);
	return (0);
}

int	mov_right(struct s_all *all)
{
	struct s_xy	pos;

	pos = search_pos(all);
	if (all->map.map[pos.y][pos.x + 1] != '1' &&
		all->map.map[pos.y][pos.x + 1] != 'E')
	{
		all->map.map[pos.y][pos.x + 1] = 'P';
		all->map.map[pos.y][pos.x] = '0';
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.none, pos.x * 20, pos.y * 20);
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.fox, (pos.x + 1) * 20, pos.y * 20);
	}
	if (all->map.map[pos.y][pos.x + 1] == 'E' && nb_item(all) == 0)
		exit(1);
	return (0);
}

int	mov_up(struct s_all *all)
{
	struct s_xy	pos;

	pos = search_pos(all);
	if (all->map.map[pos.y - 1][pos.x] != '1' &&
		all->map.map[pos.y - 1][pos.x] != 'E')
	{
		all->map.map[pos.y - 1][pos.x] = 'P';
		all->map.map[pos.y][pos.x] = '0';
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.none, pos.x * 20, pos.y * 20);
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.fox, pos.x * 20, (pos.y - 1) * 20);
	}
	if (all->map.map[pos.y - 1][pos.x] == 'E' && nb_item(all) == 0)
		exit(1);
	return (0);
}

int	mov_down(struct s_all *all)
{
	struct s_xy	pos;

	pos = search_pos(all);
	if (all->map.map[pos.y + 1][pos.x] != '1' &&
		all->map.map[pos.y + 1][pos.x] != 'E')
	{
		all->map.map[pos.y + 1][pos.x] = 'P';
		all->map.map[pos.y][pos.x] = '0';
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.none, pos.x * 20, pos.y * 20);
		mlx_put_image_to_window(all->win.mlx_ptr, all->win.mlx_win,
			all->img.fox, pos.x * 20, (pos.y + 1) * 20);
	}
	if (all->map.map[pos.y + 1][pos.x] == 'E' && nb_item(all) == 0)
		exit(1);
	return (0);
}

struct s_xy	search_pos(struct s_all *all)
{
	struct s_xy	pos;
	int			i;
	int			b;

	i = 0;
	while (all->map.map[i])
	{
		b = 0;
		while (all->map.map[i][b])
		{
			if (all->map.map[i][b] == 'P')
			{
				pos.x = b;
				pos.y = i;
				return (pos);
			}
			b++;
		}
		i++;
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}
