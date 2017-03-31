/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:33 by barnout           #+#    #+#             */
/*   Updated: 2017/03/31 14:54:03 by barnout          ###   ########.fr       */
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

int		*ini_room_mv(int size)
{
	int		i;
	int		*room;

	i = 0;
	room = (int *)malloc(sizeof(int) * size);
	while (i < size)
		room[i++] = 0;
	return (room);
}

int		nb_of_ants(char **com, int size, int room)
{
	int		i;
	int		ants;

	i = 0;
	ants = 0;
	while (i < size)
		ants += com[i++][room] - 1;
	return (ants);
}

int		first_in(int *start, int nb)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < nb)
	{
		if (start[i] != 0)
		{
			tmp = start[i];
			start[i] = 0;
			return (tmp);
		}
		i++;
	}
	return (0);
}	

void	print_moves(t_lem lem, char **com, int size, int *room, int j, int *start)
{
	int		i;
	int		first;

	if (j != 0)
	{
	i = 0;
	while (i < size)
	{
		if (com[i][j] > 1 && i != 0)
		{
			print_mv(room[i], (lem.room)[j].name);
			room[j] = room[i];
			print_moves(lem, com, size, room, j, start);
		}
		else if (com[i][j] > 1)
		{
			first = first_in(start, lem.nb);
			print_mv(first, (lem.room)[j].name);
			room[j] = first;
		}
	}
	}
}

void	ini_start(int *start, int nb)
{
	int		i;

	i = 1;
	while (i <= nb)
		start[i - 1] = i;
}

void	move_ants_no_show(t_lem lem, t_path slt, int nb, int size)
{
	int		i;
	char	**com;
	int		*room;
	int		start[lem.nb];

	printf("yo1"); //
	ini_moves(slt, size, nb);
	printf("yo2"); //
	ini_start(start, lem.nb);
	printf("yo3"); //
	room = ini_room_mv(size);
	printf("yo4"); //
	com = ini_path(size);
	printf("yo5"); //
	add_paths(slt, size, com);
	printf("yo6"); //
	print_moves(lem, com, size, room, size - 1, start);
	printf("yo7"); //
	while (still_ants(com, size, nb, slt.size))
	{
		i = 0;
		while (i < slt.size)
			move_one_step(slt.path[i++], size);
		add_paths(slt, size, com);
		print_moves(lem, com, size, room, size - 1, start);
	}
	free_path(com, size);
	free(room);
}
