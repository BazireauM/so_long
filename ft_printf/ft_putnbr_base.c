/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:23:28 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/10 14:23:58 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*test_zero(unsigned long long nbr)
{
	char	*final;

	final = NULL;
	if (nbr == 0)
	{
		final = malloc(sizeof(char) * 2);
		if (!final)
			return (NULL);
		final[0] = '0';
		final[1] = '\0';
		return (final);
	}
	return (final);
}

char	*ft_putnbr_base(unsigned long long nbr, char *base)
{
	struct s_norm_putnbr_base	test;

	test.final = test_zero(nbr);
	if (nbr == 0)
		return (test.final);
	test.a = nbr;
	test.i = 0;
	while (test.a > 0)
	{
		test.a /= 16;
		test.i++;
	}
	test.final = malloc(sizeof(char) * (test.i + 1));
	if (!test.final)
		return (NULL);
	test.i = 0;
	while (nbr > 0)
	{
		test.final[test.i] = base[nbr % 16];
		nbr /= 16;
		test.i++;
	}
	test.final[test.i] = '\0';
	return (test.final);
}
