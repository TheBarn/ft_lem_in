/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:23:25 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 12:36:44 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_room(char *str)
{
	char	**tab;

	if (count_words(str, ' ') != 3)
		return (0);
	tab = ft_strsplit(str, ' ');
	if (!is_integer(tab[1]))
	{
		free_split(tab, 3);
		return (0);
	}
	if (!is_integer(tab[2]))
	{
		free_split(tab, 3);
		return (0);
	}
	free_split(tab, 3);
	return (1);
}

t_room	*add_room(t_room *room, t_lem *lem, t_room new)
{
	t_room	*updated;
	int		i;

	lem->size += 1;
	updated = (t_room *)malloc(sizeof(t_room) * lem->size);
	i = 0;
	while (i < lem->size - 1)
	{
		updated[i] = room[i];
		i++;
	}
	updated[i] = new;
	free(room);
	return (updated);
}

void	check_sp(t_room *room, t_lem *lem)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (i < lem->size)
	{
		if (room[i].sp == 1)
			start++;
		else if (room[i].sp == 2)
			end++;
		i++;
	}
	if (start != 1 || end != 1)
		exit_lem_in("ERROR");
}

void	organize_room(t_room *room, int size)
{
	int		start;
	t_room	tmp;
	int		end;

	start = 0;
	while (start < size && room[start].sp != 1)
		start++;
	tmp = room[0];
	room[0] = room[start];
	room[start] = tmp;
	end = 0;
	while (end < size && room[end].sp != 2)
		end++;
	tmp = room[size - 1];
	room[size - 1] = room[end];
	room[end] = tmp;
}

t_room	*parse_room(int fd, t_lem *lem, char **line)
{
	t_room	*room;
	t_room	new;
	char	**split;
	int		tmp;

	room = NULL;
	tmp = 0;
	while (get_next_line(fd, line) == 1 && \
			(is_room(*line) || (*line)[0] == '#'))
	{
		printf("%s\n", *line);
		if ((*line)[0] != '#')
		{
			split = ft_strsplit(*line, ' ');
			fill_new_room(&new, split, tmp);
			tmp = 0;
			free_split(split, 3);
			room = add_room(room, lem, new);
		}
		else
			tmp = read_command(*line);
	}
	check_sp(room, lem);
	organize_room(room, lem->size);
	return (room);
}
