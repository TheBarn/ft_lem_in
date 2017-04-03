/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:33 by barnout           #+#    #+#             */
/*   Updated: 2017/04/03 20:21:38 by barnout          ###   ########.fr       */
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

void		print_moves(t_lem lem, char **com, int size, int *room, int j, int *start, int opt)
{
	int		i;
	int		first;
	int		toto;

	toto = 0;
//	ft_putnbr(j); //
	if (j != 0)
	{
	i = 0;
	while (i < size)
	{
		if (com[i][j] > 1 && i != 0 && room[i] != 0)
		{
			if (opt++ > 0)
				printf(" ");
			printf("L%d-%s", room[i], (lem.room)[j].name);
			room[j] = room[i];
			room[i] = 0;
			print_moves(lem, com, size, room, i, start, 1);
			toto++;
		}
		else if (com[i][j] > 1 && i == 0)
		{
			if (opt++ > 0)
				printf(" ");
			first = first_in(start, lem.nb);
//			printf("first is %d\n", first);
			printf("L%d-%s", first, (lem.room)[j].name);
			room[j] = first;
			toto++;
		}
		i++;
	}
	}
}

void	ini_start(int *start, int nb)
{
	int		i;

	i = 1;
	while (i <= nb)
	{
		start[i - 1] = i;
		i++;
	}
}
/*
void	print_moves(char **diff, int size, int *room)
{
	int		i;
	int		j;

	i = 0;
	increment_room(room, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (diff[i][j] > 0 && i != 0)
				increment_room_path(room, size, j, lem);
		}
	}
}*/

char	**ini_diff(int size, char **new, char **old)
{
	char	**diff;
	int		i;
	int		j;

	i = 0;
	diff = ini_path(size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			diff[i][j] = ft_max(new[i][j] - old[i][j], 0);
			j++;
		}
		i++;
	}
	return (diff);
}

void	print_from_diff(t_lem lem, char **com, char **tmp, int size, int *room, int *start)
{
	char	**diff;
	int		j;
	int		i;
	int		toto;

	diff = ini_diff(size, com, tmp);
//	print_lem(diff, size);
	j = 0;
	toto = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size)
		{
			if (diff[i][j] > 0)
			{
				if (toto == 0)
					print_moves(lem, com, size, room, j, start, toto++);
				else
					print_moves(lem, com, size, room, j, start, toto);
			}
			i++;
		}
		j++;
	}
	i = 0;
	while (i < size && diff[i][j] == 0)
		i++;
	if (i < size)
		print_moves(lem, com, size, room, j, start, toto);
}

void	put_room_color(t_lem lem, int room, int *ants)
{
	if ((lem.room)[room].sp == 1)
		ft_putroom_in_color(ants[room], 33);
	else if ((lem.room)[room].sp == 2)
		ft_putroom_in_color(ants[room], 35);
	else if (ants[room] == 0)
		ft_putroom_in_color(ants[room], 37);
	else
		ft_putroom_in_color(ants[room], 31);
}

void	print_path_color(t_lem lem, char *draw, int *ants)
{
	int		i;

	i = 0;
	while (i < (int) ft_strlen(draw))
	{
		if (draw[i] >= '0' && draw[i] <= '9' && draw[i + 1] >= '0' && draw[i + 1] <= '9')
			put_room_color(lem, find_room_id(lem, &draw[i]), ants);
		else if (!(draw[i] >= '0' && draw[i] <= '9'))
			printf("%c",draw[i]);
		i++;
	}
}

void	ini_ants(t_lem lem, int *ants)
{
	int		i;

	ants[0] = lem.nb;
	i = 1;
	while (i < lem.size)
	{
		ants[i++] = 0;
	}
}

int		ft_strcount(char *str, char c)
{
	int		i;
	int		len;
	int		toto;

	i = 0;
	toto = 0;
	len = ft_strlen(str);
	while (i < len)
		if (str[i++] == c)
			toto++;
	return (toto);
}

void	add_middle_ants(t_lem lem, int *ants, char *str)
{
	int		ant;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
	while (str[i++] != 'L');
	ant = ft_atoi(&str[i]);
	while (str[i++] != '-');
	if (find_room_id(lem, &str[i]) != lem.size - 1)
		ants[find_room_id(lem, &str[i])] = ant;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	}
}

int		nb_last_room(char *line, char *str)
{
	int		toto;
	int		i;

	i = 0;
	toto = 0;
	while (line[i] != '\0' && line[i + 1] != '\0' && line[i + 2] != '\0')
	{
		if (line[i] == str[0] && line[i + 1] == str[1] && line[i + 2] == str[2])
			toto++;
		i++;
	}
	return (toto);
}

int		count_last_room(t_lem lem, char *line)
{
	char	*str;
	int		nb;

	str = ft_strnew(3);
	str[0] = '-';
	str = ft_strcat(str, lem.room[lem.size - 1].name);
	nb = nb_last_room(line, str);
	free(str);
	return (nb);
}

void	clear_middle(int size, int *ants)
{
	int		i;

	i = 1;
	while (i < size - 1)
		ants[i++] = 0;
}

void	move_ants(t_lem lem, char *str)
{
	char	*line;
	int		ants[lem.size];
	int		toto;

	line = NULL;
	ini_ants(lem, ants);
	print_path_color(lem, str, ants);
	toto = 0;
	while (get_next_line(0, &line) == 1 && line[0] != '\0')
	{
		if (toto == 0)
			toto = ft_strcount(line, ' ') + 1;
		ants[0] = ft_max(ants[0] - toto, 0);
		add_middle_ants(lem, ants, line);
		ants[lem.size - 1] += count_last_room(lem, line);
		print_path_color(lem, str, ants);
		clear_middle(lem.size, ants);
	}
}
