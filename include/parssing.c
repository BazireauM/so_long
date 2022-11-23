/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:44:38 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/23 17:06:02 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**parssing_map(char *map)
{
	char	**final;
	char	*tmp;
	int		fd;
	int		i;

	final = NULL;
	i = 0;
	fd = open(map, O_RDONLY);
	tmp = get_next_line(fd);
	final = append_final(final, tmp);
	while (tmp)
	{
		tmp = get_next_line(fd);
		final = append_final(final, tmp);
		i++;
	}
	final = append_final(final, tmp);
	return (final);
}

char	**append_final(char **final, char *tmp)
{
	char	**tmp2;
	int		i;

	if (final == NULL)
	{
		final = malloc(sizeof(char *) * 2);
		if (!final)
			return (NULL);
		final[0] = tmp;
		final[1] = NULL;
		return (final);
	}
	tmp2 = malloc(sizeof(char *) * (len_char_char(final) + 1));
	if (!tmp2)
	{
		free_all_final(final);
		return (NULL);
	}
	i = 0;
	while (final[i])
	{
		tmp2[i] = final[i];
		i++;
	}
	tmp2[i] = NULL;
	//free_all_final(final);
	final = malloc(sizeof(char *) * (len_char_char(tmp2) + 2));
	if (!final)
	{
		free_all_final(tmp2);
		return (NULL);
	}
	i = 0;
	while (tmp2[i])
	{
		final[i] = tmp2[i];
		i++;
	}
	final[i] = tmp;
	final[i + 1] = NULL;
	free(tmp2);
	return (final);
}

int	free_all_final(char **final)
{
	int	i;

	i = 0;
	if (!final[i])
		return (0);
	while (final[i])
	{
		free(final[i]);
		printf("%d\n", i);
		i++;
	}
	free(final[i]);
	free(final);
	return (0);
}

int	len_char_char(char **final)
{
	int	i;

	i = 0;
	if (!final)
		return (0);
	while (final[i])
		i++;
	return (i);
}
