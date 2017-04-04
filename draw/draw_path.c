/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:08 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:51:25 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_putroom_in_color(int room, int color)
{
	int		d;
	int		r;

	d = room / 10;
	r = room % 10;
	ft_printf("\e[%d;m%c\e[0;m", color, d + '0');
	ft_printf("\e[%d;m%c\e[0;m", color, r + '0');
}

void	ft_putroom_id(t_lem lem, int room, int nb_slt, int toto)
{
	if (room == 0 || room == lem.size - 1)
	{
		if (room == lem.size - 1 && toto == lem.nb + nb_slt)
			ft_putroom_in_color(toto - nb_slt, 32);
		else if (room == lem.size - 1 && toto > nb_slt)
			ft_putroom_in_color(toto - nb_slt, 31);
		else if (room == lem.size - 1)
			ft_putroom_in_color(toto - nb_slt, 35);
		else
			ft_putroom_in_color(toto, 33);
	}
	else if (toto > 1)
		ft_putroom_in_color(toto - 1, 31);
	else
		ft_printf("00");
}

void	ft_putroom(t_lem lem, char **path, int room, int nb_slt)
{
	int		i;
	int		color;
	int		toto;

	i = 0;
	color = 33;
	toto = 0;
	while (i < lem.size)
		toto += path[i++][room];
	if (toto != 0)
		ft_putroom_id(lem, room, nb_slt, toto);
	else
		ft_printf("00");
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

void	draw_from_path(t_lem lem, char **path, char *draw, int nb_slt)
{
	int		i;
	int		len;

	len = ft_strlen(draw);
	i = 0;
	while (i < len)
	{
		if (draw[i] >= '0' && draw[i] <= '9' && \
				draw[i + 1] >= '0' && draw[i + 1] <= '9')
			ft_putroom(lem, path, find_room_id(lem, &draw[i]), nb_slt);
		else if (!(draw[i] >= '0' && draw[i] <= '9'))
			ft_printf("%c", draw[i]);
		i++;
	}
	ft_printf("\n\n");
}
