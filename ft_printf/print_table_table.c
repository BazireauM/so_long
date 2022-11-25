/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:23:45 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 12:54:33 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_table_table(char **final)
{
	int		a;
	size_t	b;

	a = 0;
	b = 0;
	while (final[a] != NULL)
	{
		ft_putstr_fd(final[a], 1);
		b += ft_strlen(final[a]);
		a++;
	}
	return (b);
}
