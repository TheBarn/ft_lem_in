/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:33 by barnout           #+#    #+#             */
/*   Updated: 2017/04/07 14:16:30 by barnout          ###   ########.fr       */
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

int		still_ants(t_lem lem, int nb_path)
{
	int		i;
	int		toto;

	i = 0;
	toto = 0;
	while (i < lem.size)
		toto += lem.map[i++][lem.size - 1];
	if (toto != lem.nb + nb_path)
		return (1);
	return (0);
}

void	ini_room_mv(t_lem lem)
{
	int		i;

	i = 0;
	while (i < lem.size)
		lem.room[i++].sp = 0;
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

void	move_ants_no_show(t_lem lem, t_path *slt)
{
	int		i;
	char	**tmp;
	char	**diff;
	int		start[lem.nb];

	ini_moves(slt, lem.size, lem.nb);
	ini_start(start, lem.nb);
	ini_room_mv(lem);
	add_paths(*slt, lem.size, lem.map);
	while (still_ants(lem, slt->size))
	{
		tmp = ft_lemcpy(lem.map, lem.size);
		i = 0;
		while (i < slt->size)
			move_one_step(slt->path[i++], lem.size);
		add_paths(*slt, lem.size, lem.map);
		diff = ini_diff(lem.size, lem.map, tmp);
		print_from_diff(lem, diff, start);
		free_path(diff, lem.size);
		free_path(tmp, lem.size);
		ft_printf("\n");
	}
}
