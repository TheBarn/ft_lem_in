/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:01:23 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 15:09:36 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lem		update_lem(char **map, int size)
{
	t_lem	lem;

	lem.map = ft_lemcpy(map, size);
	lem.size = size;
	return (lem);
}

t_path		algo(t_lem old)
{
	t_path	slt;
	char	**new_path;
	t_lem	lem;

	slt.path = NULL;
	slt.size = 0;
	lem = update_lem(old.map, old.size);
	while (lem.size > 0)
	{
		new_path = find_shortest_path(lem);
		if (new_path != NULL)
		{
			add_new_path(&slt, new_path);
			prune_lem(lem.map, new_path, lem.size);
		}
		else
			lem.size = 0;
	}
	free_path(lem.map, old.size);
	return (slt);
}
