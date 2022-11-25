/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:35:27 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 15:01:00 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_p2(char *s, int *c, int *a, int i)
{
	*c = write(1, &"0x", 2);
	if (*c == -1)
	{
		free(s);
		return (-1);
	}
	*a += *c;
	while (i >= 0)
	{
		*c = write(1, &s[i], 1);
		if (*c == -1)
		{
			free(s);
			return (-1);
		}
		*a += *c;
		i--;
	}
	return (0);
}

int	choose_p(va_list arg, int *a)
{
	unsigned long long	b;
	char				*s;
	int					c;
	int					i;

	b = va_arg(arg, unsigned long long);
	s = ft_putnbr_base(b, "0123456789abcdef");
	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
		i++;
	i--;
	c = choose_p2(s, &c, a, i);
	if (c == -1)
		return (-1);
	free(s);
	return (0);
}
