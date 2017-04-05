/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:29:39 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 15:46:39 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*draw_paths_only(t_lem lem, t_path slt)
{
	char	*str;
	char	**com;

	com = ini_path(lem.size);
	add_paths(slt, lem.size, com);
	str = draw_lem(lem, com);
	free_path(com, lem.size);
	return (str);
}

void	ft_put_sp_color(t_lem lem, int room)
{
	if ((lem.room)[room].sp == 1)
		ft_putroom_in_color(ft_atoi(lem.room[room].name), 33);
	else if ((lem.room)[room].sp == 2)
		ft_putroom_in_color(ft_atoi(lem.room[room].name), 35);
	else
		ft_putroom_in_color(ft_atoi(lem.room[room].name), 37);
}

void	print_lem_color(t_lem lem, char *draw)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(draw))
	{
		if (draw[i] >= '0' && draw[i] <= '9' && draw[i + 1] >= '0' \
				&& draw[i + 1] <= '9')
			ft_put_sp_color(lem, find_room_id(lem, &draw[i]));
		else if (!(draw[i] >= '0' && draw[i] <= '9'))
			ft_printf("%c", draw[i]);
		i++;
	}
	ft_printf("\n");
}

int		main(void)
{
	t_lem	lem;
	t_path	slt;
	int		i;
	char	*str;
	char	*draw;

	lem = parser(1);
	draw = draw_lem(lem, lem.map);
	ft_printf("\nThe anthill can be representated this way, with \e[33;mSTART\e[0;m and \e[35;mEND\e[0;m :\n\n");
	print_lem_color(lem, draw);
	exc_paths(lem, draw);
	slt = algo(lem);
	check_path(slt.size);
	str = draw_paths_only(lem, slt);
	ft_printf("We will only use %d path(s) in the anthill, from \e[33;mSTART\e[0;m to \e[35;mEND\e[0;m :\n\n", slt.size);
	move_ants(lem, str);
	i = 0;
	while (i < slt.size)
		free_path((slt.path)[i++], lem.size);
	free(slt.path);
	free_path(lem.map, lem.size);
	i = 0;
	while (i < lem.size)
		free(lem.room[i++].name);
	free(lem.room);
	free(str);
	free(draw);
	return (0);
}
