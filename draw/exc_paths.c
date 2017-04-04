/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:05:29 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:48:57 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		exc_paths(t_lem lem, char *draw)
{
	char	**com;

	if ((lem.map)[0][lem.size - 1] == 1)
	{
		ft_printf("%d ant(s) will travel in the anthill.\nThere is a direct pipe \
		from \e[33;mSTART\e[0;m to \e[35;mEND\e[0;m, ants will move together \
		from \e[33;mSTART\e[0;m to \e[35;mEND\e[0;m in one move.\n\n", lem.nb);
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
		ft_printf("There is no path linking \e[33;mSTART\e[0;m to \
				\e[35;mEND\e[0;m in the anthill. Ants will not move.\n\n");
		exit(0);
	}
}
