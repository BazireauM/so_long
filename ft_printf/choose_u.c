/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:30:08 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 14:25:39 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_u(va_list arg, int *a)
{
	unsigned int	b;
	char			*test;
	int				i;
	int				c;

	b = va_arg(arg, unsigned int);
	test = ft_itoa_u(b);
	i = 0;
	if (test == NULL)
		return (-1);
	while (test[i])
	{
		c = write(1, &test[i], 1);
		if (c == -1)
		{
			free(test);
			return (-1);
		}
		*a += c;
		i++;
	}
	free(test);
	return (0);
}
