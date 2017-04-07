/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:57:54 by barnout           #+#    #+#             */
/*   Updated: 2017/04/07 14:15:33 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move_ant(char **path, int i, int j, int size)
{
	int		k;

	if (j != size - 1)
	{
		k = 1;
		while (path[j][k] == 0)
			k++;
		path[i][j]--;
		path[j][k]++;
		if (k != size - 1 && path[j][k] > 2)
			move_ant(path, j, k, size);
	}
}

int		first_room(char **path, int size, int i)
{
	int		j;

	if (i == 0 && path[0][0] > 0)
		return (0);
	else
	{
		j = 0;
		while (j < size && path[i][j] == 0)
			j++;
		if (path[i][j] > 1)
			return (j);
		return (first_room(path, size, j));
	}
	return (0);
}

void	move_one_step(char **path, int size)
{
	int		j;
	int		i;

	j = first_room(path, size, 0);
	i = 0;
	while (i < size && path[i][j] == 0)
		i++;
	move_ant(path, i, j, size);
}

int		add_paths_in(t_path slt, int i, int j)
{
	int		toto;
	int		a;

	toto = 0;
	a = 0;
	while (a < slt.size)
	{
		toto += (slt.path[a])[i][j];
		a++;
	}
	return (toto);
}

void	add_paths(t_path slt, int size, char **com)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			com[i][j] = add_paths_in(slt, i, j);
			j++;
		}
		i++;
	}
}
