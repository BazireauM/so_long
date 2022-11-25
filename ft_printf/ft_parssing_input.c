/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parssing_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:36:00 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/09 12:54:03 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_n_arg(const char *s)
{
	int	a;
	int	n_arg;

	n_arg = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] == '%')
		{
			n_arg++;
			if (s[a + 1])
				a++;
		}
		a++;
	}
	return (n_arg);
}

int	count_n_txt(const char *s)
{
	int	i;
	int	n_txt;

	n_txt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			while (s[i] && s[i] != '%')
			{
				i++;
			}
			n_txt++;
		}
		else
			i += 2;
	}
	return (n_txt);
}

char	*arg_char(const char *s, int n_arg)
{
	int		i;
	int		a;
	char	*arg_char_final;

	i = 0;
	a = 0;
	arg_char_final = malloc(sizeof(char) * (n_arg + 1));
	if (!arg_char_final)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			arg_char_final[a] = s[i];
			a++;
		}
		i++;
	}
	arg_char_final[a] = '\0';
	return (arg_char_final);
}
