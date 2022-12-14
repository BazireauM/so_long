/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:57:39 by mbazirea          #+#    #+#             */
/*   Updated: 2022/12/09 11:21:21 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_file(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == 'r' && s[i - 2] == 'e' && s[i - 3] == 'b'
		&& s[i - 4] == '.')
		return (0);
	return (1);
}
