/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:05:26 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 19:21:04 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			*ini_room(int size)
{
	int		i;
	int		*room;

	room = (int *)my_malloc(sizeof(int) * size);
	room[0] = 0;
	i = 1;
	while (i < size)
		room[i++] = -1;
	return (room);
}

void		add_new_path(t_path *slt, char **new, int size)
{
	char	***tmp;
	int		i;

	tmp = slt->path;
	slt->path = (char ***)my_malloc(sizeof(char **) * (slt->size + 1));
	i = 0;
	while (i < slt->size)
	{
		(slt->path)[i] = ft_lemcpy(tmp[i], size);
		free_path(tmp[i], size);
		i++;
	}
	if (!tmp)
		free(tmp);
	(slt->path)[i] = new;
	slt->size += 1;
}

void		add_next_branches(t_lem lem, char **path, int i, int *room)
{
	int		j;
	int		k;

	j = 0;
	while (j < lem.size)
	{
		if (room[j] == i)
		{
			k = 0;
			while (k < lem.size)
			{
				while (lem.map[j][k] == 0)
					k++;
				if (k < lem.size && lem.map[k][k] == 0)
				{
					lem.map[k][k] = 1;
					room[k] = i + 1;
					path[j][k] = 1;
				}
				k++;
			}
		}
		j++;
	}
}

int			compare_room(int *room, int *tmp, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (room[i] != tmp[i])
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

char		**find_shortest_path(t_lem lem)
{
	char	**path;
	int		i;
	int		*room;
	int		*tmp;

	path = ini_path(lem.size);
	room = ini_room(lem.size);
	i = 0;
	tmp = ft_tabcpy(room, lem.size);
	add_next_branches(lem, path, i++, room);
	while (compare_room(room, tmp, lem.size))
	{
		tmp = ft_tabcpy(room, lem.size);
		add_next_branches(lem, path, i++, room);
	}
	if (room[lem.size - 1] == -1)
		return (NULL);
	path = prune_path(path, lem.size, room);
	free(room);
	free_path(lem.map, lem.size);
	return (path);
}
