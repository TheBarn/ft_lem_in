/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:29:39 by barnout           #+#    #+#             */
/*   Updated: 2017/03/31 12:03:16 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

char	*draw_paths_only(t_lem *lem, t_path slt)
{
	//	int		i;
	char	*str;
	char	**com;

	//	i = 0;
	//	while (i < slt.size)
	//		print_lem(slt.path[i++], lem->size);
	com = ini_path(lem->size);
	add_paths(slt, lem->size, com);
	str = draw_lem(lem, com);
	free_path(com, lem->size);
	return (str);
}

void	ft_put_sp_color(t_lem lem, int room)
{
	if ((lem.room)[room].sp == 1)
		ft_putroom_in_color(room, 33);
	else if ((lem.room)[room].sp == 2)
		ft_putroom_in_color(room, 35);
	else
		ft_putroom_in_color(room, 37);
}

void	print_lem_color(t_lem lem, char *draw)
{
	int		i;

	i = 0;
	while (i < (int) ft_strlen(draw))
	{
		if (draw[i] >= '0' && draw[i] <= '9' && draw[i + 1] >= '0' && draw[i + 1] <= '9')
			ft_put_sp_color(lem, find_room_id(lem, &draw[i]));
		else if (!(draw[i] >= '0' && draw[i] <= '9'))
			printf("%c",draw[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_lem	lem;
	t_path	slt;
	int		i;
	char	*str;
	char	*draw;


	if (ac != 2)
	{
		printf("Indicate the name of the file to opened as parameter.\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		printf("The file cannot be opened\n");
		return (0);
	}
	lem = parser(fd);
	draw = draw_lem(&lem, lem.map);
	printf("\nThe anthill can be representated this way, with \e[33;mSTART\e[0;m and \e[35;mEND\e[0;m :\n\n");
	print_lem_color(lem, draw);
	exc_paths(lem, draw);
	//	print_rooms_order(lem);
	slt = algo(lem.map, lem.size);
	check_path(slt.size);
	str = draw_paths_only(&lem, slt);
	printf("We will only use %d path(s) in the anthill, from \e[33;mSTART\e[0;m to \e[35;mEND\e[0;m :\n\n", slt.size);
	print_lem_color(lem, str);
	printf("\n%d ant(s) will travel in the anthill from \e[33;mSTART\e[0;m to \e[35;mEND\e[0;m.\nThere can be no more than one ant in every room, except for \e[33;mSTART\e[0;m and \e[35;mEND\e[0;m which do not have a maximum number of ants.\nEach room are representated by numbers, according to the number of ants they contain.\n\n", lem.nb);
	move_ants(lem, slt, lem.nb, lem.size, str);
	i = 0;
	while (i < slt.size)
		free_path((slt.path)[i++], lem.size);
	free(slt.path);
	free(str);
	free(draw);
	return (0);
}
