/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:37:55 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 12:38:32 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**ini_path(int size)
{
	char	**new;
	int		i;
	int		j;

	new = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		new[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
			new[i][j++] = 0;
		i++;
	}
	return (new);
}

void		print_lem(char **lem, int size)
{
	int		i;
	int		j;

	if (lem != NULL)
	{
		i = 0;
		ft_putchar('\n');
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				ft_putchar('0' + lem[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
	}
}

char		**ft_lemcpy(char **lem, int size)
{
	char	**new;
	int		i;
	int		j;

	new = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		new[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			new[i][j] = lem[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

void		free_path(char **path, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(path[i++]);
	free(path);
}
