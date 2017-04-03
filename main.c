/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:46:49 by barnout           #+#    #+#             */
/*   Updated: 2017/04/03 14:23:27 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void		print_mv(int ant, char *room)
{
	printf("L%d-%s ", ant, room);
}

void		print_mv_l(int ant, char *room)
{
	printf("L%d-%s\n", ant, room);
}

void		direct_path(t_lem lem)
{
	int		i;

	if ((lem.map)[0][lem.size - 1] == 1)
	{
		i = 0;
		while (i < lem.nb - 1)
			print_mv(i++ + 1, (lem.room)[lem.size - 1].name);
		print_mv_l(i + 1, (lem.room)[lem.size - 1].name);
		exit(0);
	}
}

int		main(void)
{
	t_lem	lem;
	t_path	slt;
	int		i;

	lem = parser(0);
	direct_path(lem);
	slt = algo(lem.map, lem.size);
	if (slt.size == 0)
		exit_lem_in("no path found between START and END");
	move_ants_no_show(lem, slt, lem.nb, lem.size);
	i = 0;
	while (i < slt.size)
		free_path((slt.path)[i++], lem.size);
	free(slt.path);
	return (0);
}
