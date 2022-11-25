/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:19:25 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 14:31:47 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_x(va_list arg, int *a)
{
	struct s_norm_x	test;

	test.b = va_arg(arg, unsigned int);
	test.s = ft_putnbr_base(test.b, "0123456789abcdef");
	test.i = 0;
	if (!test.s)
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
