/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:01:23 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:49:53 by barnout          ###   ########.fr       */
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

t_path		algo(char **map, int size)
{
	t_path	slt;
	char	**new_path;
	t_lem	lem;

	slt.path = NULL;
	slt.size = 0;
	lem = update_lem(map, size);
	while (size > 0)
	{
		new_path = find_shortest_path(lem);
		if (new_path != NULL)
		{
			add_new_path(&slt, new_path, size);
			prune_lem(map, new_path, size);
		}
		else
			size = 0;
	}
	return (slt);
}
