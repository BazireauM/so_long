/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:21:47 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 14:18:31 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_else_if_else(va_list arg, struct s_norm *test, const char *s)
{
	if (s[test->i] != '%' && s[test->i])
	{
		test->c = write(1, &s[test->i], 1);
		if (test->c == -1)
			return (-1);
		test->a++;
		test->i++;
	}
	else if (s[test->i] == '%' && s[test->i + 1])
	{
		test->c = choose_type(arg, (char)s[test->i + 1], &test->a);
		if (test->c == -1)
			return (-1);
		test->i += 2;
	}
	else
		test->i++;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			arg;
	struct s_norm	test;
	int				w;

	va_start(arg, s);
	test.i = 0;
	test.d = 0;
	test.a = 0;
	while (s[test.i])
	{
		w = if_else_if_else(arg, &test, s);
		if (w == -1)
			return (-1);
	}
	return (test.a);
}
