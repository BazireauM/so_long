/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:55:57 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 15:32:56 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_s(va_list arg, int *a)
{
	char	*s;
	int		c;
	int		i;

	s = va_arg(arg, char *);
	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			c = write(1, &s[i], 1);
			if (c == -1)
				return (-1);
			*a += c;
			i++;
		}
	}
	else
	{
		c = write (1, &"(null)", 6);
		if (c == -1)
			return (-1);
		*a += c;
	}
	return (0);
}
