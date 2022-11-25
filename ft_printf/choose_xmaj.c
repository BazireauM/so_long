/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_xmaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:31:11 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 14:35:11 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_xmaj(va_list arg, int *a)
{
	struct s_norm_x	test;

	test.b = va_arg(arg, unsigned int);
	test.s = ft_putnbr_base(test.b, "0123456789ABCDEF");
	test.i = 0;
	if (test.s == NULL)
		return (-1);
	while (test.s[test.i])
		test.i++;
	test.i--;
	while (test.i >= 0)
	{
		test.c = write(1, &test.s[test.i], 1);
		if (test.c == -1)
		{
			free(test.s);
			return (-1);
		}
		*a += test.c;
		test.i--;
	}
	free(test.s);
	return (0);
}
