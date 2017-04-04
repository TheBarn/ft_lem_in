/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prune.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:01:13 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 11:12:25 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			prune_room(char **lem, int j, int size)
{
	int		i;
	int		toto;

	toto = 0;
	if (j == size - 1)
		return (0);
	i = 0;
	while (i < size)
		lem[i++][j] = 0;
	i = 0;
	while (i < size)
		lem[j][i++] = 0;
	return (1);
}

int			prune_lem(char **lem, char **path, int size)
{
	int		i;
	int		j;
	int		toto;

	i = 0;
	toto = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (path[i][j] == 1)
				toto += prune_room(lem, j, size);
			j++;
		}
		i++;
	}
	return (toto);
}

int			is_vertex(int *vertex, int size, int i, int j)
{
	int		k;

	k = 0;
	while (k < size)
	{
		if (vertex[2 * k] == i && vertex[2 * k + 1] == j)
			return (1);
		k++;
	}
	return (0);
}

int			*ini_vertex(char **path, int size, int len)
{
	int		*vertex;
	int		i;
	int		j;
	int		k;

	vertex = (int *)malloc(sizeof(int) * len);
	j = size - 1;
	k = 0;
	while (j > 0)
	{
		i = size - 1;
		while (i >= 0 && path[i][j] != 1)
			i--;
		vertex[k++] = i;
		vertex[k++] = j;
		j = i;
	}
	return (vertex);
}

char		**prune_path(char **path, int size, int *room)
{
	int		*vertex;
	int		i;
	int		j;
	char	**new;

	vertex = ini_vertex(path, size, 2 * room[size - 1]);
	new = ini_path(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (is_vertex(vertex, room[size - 1], i, j))
				new[i][j] = 1;
			j++;
		}
		i++;
	}
	free_path(path, size);
	return (new);
}
