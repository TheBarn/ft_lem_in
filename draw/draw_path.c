/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:08 by barnout           #+#    #+#             */
/*   Updated: 2017/04/03 16:55:36 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_putroom_in_color(int room, int color)
{
	int		d;
	int		r;

	d = room / 10;
	r = room % 10;
	printf("\e[%d;m%c\e[0;m", color, d + '0');
	printf("\e[%d;m%c\e[0;m", color, r + '0');
}

void	ft_putroom(char **path, int size, int room, int nb, int nb_slt)
{
	int		i;
	int		color;
	int		toto;

	i = 0;
	color = 33;
	toto = 0;
//	printf("room is %d, nb is %d, nb_slt is %d\n", room, nb, nb_slt);
	while (i < size)
		toto += path[i++][room];
	if (toto != 0)
	{
		if (room == 0 || room == size - 1)
		{
			if (room == size - 1 && toto == nb + nb_slt)
				ft_putroom_in_color(toto - nb_slt, 32);
			else if (room == size - 1 && toto > nb_slt)
				ft_putroom_in_color(toto - nb_slt, 31);
			else if (room == size - 1)
				ft_putroom_in_color(toto - nb_slt, 35);
			else
				ft_putroom_in_color(toto, 33);
		}
		else if (toto > 1)
		{
		//	printf("char to print in color is %c\n", room + '0');
			ft_putroom_in_color(toto - 1, 31);
		}
		else
			printf("00");
	}
	else
		printf("00");
}

int		find_room_id(t_lem lem, char *str)
{
	int		i;

	i = 0;
	while (i < lem.size)
	{
		if (ft_strncmp(str, (lem.room)[i].name, 2) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	draw_from_path(t_lem lem,char **path, int size, char *draw, int nb, int nb_slt)
{
	int		i;
	int		len;

	len = ft_strlen(draw);
	i = 0;
//	printf("\n\n%s\n\n", draw);
//	print_lem(path, size);
	while (i < len)
	{
		if (draw[i] >= '0' && draw[i] <= '9' && draw[i + 1] >= '0' && draw[i + 1] <= '9')
			ft_putroom(path, size, find_room_id(lem, &draw[i]), nb, nb_slt);
		else if (!(draw[i] >= '0' && draw[i] <= '9'))
			printf("%c",draw[i]);
		i++;
	}
	printf("\n\n");
}
