/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:33 by barnout           #+#    #+#             */
/*   Updated: 2017/03/31 11:24:32 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		sizeof_path(char **path, int size)
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
			if (path[i][j++] == 1)
				toto++;
		i++;
	}
	return (toto);
}

void	change_to_star(char **path, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (path[i][j] == 1)
			{
				printf("yolo");
				path[i][j] = '*';
			}
			j++;
		}
		i++;
	}
}

int		*ini_nb_path(t_path slt)
{
	int		i;
	int		*nb_path;

	i = 0;
	nb_path = (int *)malloc(sizeof(int) * slt.size);
	while (i < slt.size)
		nb_path[i++] = 0;
	return (nb_path);
}

int		*ini_length(int size, t_path slt)
{
	int		i;
	int		*length;

	i = 0;
	length = (int *)malloc(sizeof(int) * slt.size);
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

void	ini_moves(t_path slt, int size, int nb)
{
	int		*length;
	int		*nb_path;

	nb_path = ini_nb_path(slt);
	length = ini_length(size, slt);
	fill_nb_path(nb, nb_path, length, slt.size);
	to_starting_blocks(slt, nb_path);
	free(length);
	free(nb_path);
}

int		still_ants(char **path, int size, int nb, int nb_path)
{
	int		i;
	int		toto;
	
	i = 0;
	toto = 0;
	while (i < size)
		toto += path[i++][size - 1];
	if (toto != nb + nb_path)
		return (1);
	return (0);
}

void	move_to_next(char **path, int size, int i, int j)
{
	path[i][j]--;
	i = j;
	j = 1;
	if (i == size - 1)
		path[size - 1][size - 1]++;
	else
	{
		while (j < size && path[i][j] == 0)
			j++;
		path[i][j]++;
	}
}

void	move_one_step(char **path, int size)
{
	int		i;
	int		j;

	i = size - 1;
	while (i >= 0)
	{
		j = size - 1;
		while (j >= 0)
		{
			if (i == 0 && j == 0 && path[i][j] > 0)
				move_to_next(path, size, i, j);
			else if (j != size - 1 && path[i][j] > 1)
				move_to_next(path, size, i, j);
			j--;
		}
		i--;
	}
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

void	move_ants(t_lem lem, t_path slt, int nb, int size, char *draw)
{
	int		i;
	char	**com;
	int		toto;

	ini_moves(slt, size, nb);
	com = ini_path(size);
	add_paths(slt, size, com);
//	print_lem(com, size); //
	draw_from_path(lem, com, size, draw, nb, slt.size);
	toto = 0;
	while (still_ants(com, size, nb, slt.size))
	{
		i = 0;
		while (i < slt.size)
			move_one_step(slt.path[i++], size);
		add_paths(slt, size, com);
//		print_lem(com, size); //
		draw_from_path(lem, com, size, draw, nb, slt.size);
		toto++;
	}
	printf("The ants moved from \e[33;mSTART\e[0;m to \e[35;mEND\e[0;m in %d moves.\n\n", toto);
	free_path(com, size);
}
