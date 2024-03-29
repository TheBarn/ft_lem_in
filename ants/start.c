/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:56:34 by barnout           #+#    #+#             */
/*   Updated: 2017/04/07 14:57:27 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*ini_length(int size, t_path slt)
{
	int		i;
	int		*length;

	i = 0;
	length = (int *)my_malloc(sizeof(int) * slt.size);
	while (i < slt.size)
	{
		length[i] = sizeof_path(slt.path[i], size);
		i++;
	}
	return (length);
}

void	fill_nb_path(int nb, int *nb_path, int *length, int size)
{
	int		min_id;
	int		min;
	int		i;

	while (nb > 0)
	{
		i = 0;
		min_id = 0;
		min = length[0];
		while (i < size)
		{
			if (length[i] < min)
			{
				min_id = i;
				min = length[i];
			}
			i++;
		}
		length[min_id]++;
		nb_path[min_id]++;
		nb--;
	}
}

void	to_starting_blocks(t_path slt, int *nb_path)
{
	int		i;

	i = 0;
	while (i < slt.size)
	{
		(slt.path[i])[0][0] = nb_path[i];
		i++;
	}
}

void	prune_slt(t_path *slt)
{
	int		i;
	char	**tmp;

	i = 0;
	while (i < slt->size)
	{
		if ((slt->path[i])[0][0] == 0)
		{
			tmp = slt->path[i];
			slt->path[i] = slt->path[slt->size - 1];
			slt->path[slt->size - 1] = tmp;
			free(slt->path[slt->size - 1]);
			slt->size--;
			i = -1;
		}
		i++;
	}
}

void	ini_moves(t_path *slt, int size, int nb)
{
	int		*length;
	int		*nb_path;

	nb_path = ini_nb_path(*slt);
	length = ini_length(size, *slt);
	fill_nb_path(nb, nb_path, length, slt->size);
	to_starting_blocks(*slt, nb_path);
	free(length);
	free(nb_path);
	prune_slt(slt);
}
