/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:28:39 by barnout           #+#    #+#             */
/*   Updated: 2017/03/30 18:13:19 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		add_to_ref(int *ref, int size, int j)
{
	int		i;

	i = size - 1;
	while (i >= 0)
		if (ref[i--] == j)
			return (0);
	i = size - 1;
	while (i >= 0 && ref[i] != -1)
		i--;
	if (i != size)
		ref[i] = j;
	return (1);
}

void	get_ref_from(t_lem lem, int *ref, int cl)
{
	int		i;

	i = 0;
	while (i < lem.size)
	{
		if ((lem.map)[i][cl] == 1 && i != 0)
		{
			if (add_to_ref(ref, lem.size, i))
				get_ref_from(lem, ref, i);
		}
		i++;
	}
}

int		fill_with_other(int *ref, int size)
{
	int		k;
	int		l;
	int		toto;

	k = 0;
	while (k < size)
	{
		l = 0;
		toto = 0;
		while (l < size)
			if (ref[l++] == k)
				toto++;
		if (toto == 0)
			return (k);
	}
	return (0);
}

void	ini_ref(t_lem lem, int *ref, int size)
{
	int		i;

	ref[0] = 0;
	i = 1;
	while (i < size - 1)
		ref[i++] = -1;
	ref[size - 1] = size - 1;
	get_ref_from(lem, ref, size - 1);
	i = 0;
	while (i < size)
	{
		if (ref[i] == -1)
			ref[i] = fill_with_other(ref, size);
		i++;
	}
}


t_room		*order_room(int *ref, t_lem lem)
{
	int		i;
	t_room	*room;

	i = 0;
	room = (t_room *)malloc(sizeof(t_room) * lem.size);
	while (i < lem.size)
	{
		if (ref[i] != -1)
			room[i] = (lem.room)[ref[i]];
		i++;
	}
	free(lem.room);
	return (room);
}

int		rank_in_ref(int *ref, int i, int size)
{
	int		k;

	k = 0;
	while (k < size)
	{
		if (ref[k] == i)
			return (k);
		k++;
	}
	return (0);
}

char	**permute_map(char **map, int size, int *ref)
{
	char	**new;
	int		i;
	int		j;

	new = ini_path(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == 1)
				new[rank_in_ref(ref, i, size)][rank_in_ref(ref, j, size)] = 1;
			j++;
		}
		i++;
	}
	free_path(map,size);
	return (new);
}

void	trunc_map(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
			map[i][j++] = 0;
		i++;
	}
}

void	put_in_order(t_lem *lem)
{
	int		i;
	int		ref[lem->size];

	i = lem->size - 1;
	ini_ref(*lem, ref, lem->size);
	print_tab(ref, lem->size);
	print_rooms_order(*lem); //
	lem->room = order_room(ref, *lem);
	lem->map = permute_map(lem->map, lem->size, ref);
	printf("\n");
	print_rooms_order(*lem); //
	trunc_map(lem->map, lem->size);
}
