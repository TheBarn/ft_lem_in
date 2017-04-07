/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:05:29 by barnout           #+#    #+#             */
/*   Updated: 2017/04/07 11:23:21 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		exc_paths(t_lem lem, char *draw)
{
	char	**com;

	if ((lem.map)[0][lem.size - 1] == 1)
	{
		ft_printf("direct path >> ants will move together\n\n");
		com = ini_path(lem.size);
		com[0][0] = lem.nb;
		com[0][lem.size - 1] = 1;
		draw_from_path(lem, com, draw, 1);
		com[0][0] = 0;
		com[0][lem.size - 1] = lem.nb + 1;
		draw_from_path(lem, com, draw, 1);
		exit(0);
	}
}

void		check_path(int size)
{
	if (size == 0)
	{
		ft_printf("No path found.\n\n");
		exit(0);
	}
}
