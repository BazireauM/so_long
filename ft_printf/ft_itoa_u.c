/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:31:03 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 16:43:48 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*malloc_final_u(unsigned int n2, int *a)
{
	char			*final;

	*a = 0;
	while (n2 > 0)
	{
		n2 /= 10;
		*a = *a + 1;
	}
	final = malloc(sizeof(char) * *a + 1);
	if (!final)
		return (NULL);
	final[*a] = '\0';
	return (final);
}

void	zero_u(char *final)
{
	final[0] = '0';
	final[1] = '\0';
}

char	*ft_itoa_part2_u(int a, unsigned int n, char *final, unsigned int n2)
{
	while (a > 0 && n != 0)
	{
		final[a - 1] = '0' + n2 % 10;
		n2 /= 10;
		a--;
	}
	return (final);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*final;
	unsigned int	n2;
	int				a;

	if (n == 0)
	{
		final = malloc(2);
		if (!final)
			return (NULL);
		zero_u(final);
		return (final);
	}
	n2 = n;
	final = malloc_final_u(n2, &a);
	if (!final)
		return (NULL);
	ft_itoa_part2_u(a, n, final, n2);
	return (final);
}
