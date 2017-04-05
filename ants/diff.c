/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:58:39 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 17:02:25 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

void	print_ant_move(t_lem lem, int *start, int i, int j)
{
	int		first;

	if (lem.map[i][j] > 1 && i != 0 && lem.room[i].sp != 0)
	{
		ft_printf("L%d-%s", lem.room[i].sp, (lem.room)[j].name);
		lem.room[j].sp = lem.room[i].sp;
		lem.room[i].sp = 0;
		print_moves(lem, i, start, 1);
	}
	else if (lem.map[i][j] > 1 && i == 0)
	{
		first = first_in(start, lem.nb);
		ft_printf("L%d-%s", first, (lem.room)[j].name);
		lem.room[j].sp = first;
	}
}

void	print_moves(t_lem lem, int j, int *start, int opt)
{
	int		i;

	if (j != 0)
	{
		i = 0;
		while (i < lem.size)
		{
			if (lem.map[i][j] > 1 && (i == 0 || \
						(i != 0 && lem.room[i].sp != 0)))
			{
				if (opt++ > 0)
					ft_printf(" ");
				print_ant_move(lem, start, i, j);
			}
			i++;
		}
	}
}

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

void	print_from_diff(t_lem lem, char **diff, int *start)
{
	int		j;
	int		i;
	int		toto;

	j = 0;
	toto = 0;
	while (j < lem.size - 1)
	{
		i = 0;
		while (i < lem.size)
		{
			if (diff[i++][j] > 0)
				print_moves(lem, j, start, toto++);
		}
		j++;
	}
	i = 0;
	while (i < lem.size && diff[i][j] == 0)
		i++;
	if (i < lem.size)
		print_moves(lem, j, start, toto);
}
