/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:06 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 13:53:54 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_d(va_list arg, int *a)
{
	struct s_norm2	test;

	test.b = va_arg(arg, int);
	test.s = ft_itoa(test.b);
	test.i = 0;
	if (test.s == NULL)
	{
		free(test.s);
		return (-1);
	}
	while (test.s[test.i])
	{
		test.c = write(1, &test.s[test.i], 1);
		if (test.c == -1)
		{
			free(test.s);
			return (-1);
		}
		*a += test.c;
		test.i++;
	}
	free(test.s);
	return (0);
}
