/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:07:12 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:38:35 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_room_color(t_lem lem, int room, int *ants)
{
	if ((lem.room)[room].sp == 1)
		ft_putroom_in_color(ants[room], 33);
	else if ((lem.room)[room].sp == 2)
		ft_putroom_in_color(ants[room], 35);
	else if (ants[room] == 0)
		ft_putroom_in_color(ants[room], 37);
	else
		ft_putroom_in_color(ants[room], 31);
}

void	print_path_color(t_lem lem, char *draw, int *ants)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(draw))
	{
		if (draw[i] >= '0' && draw[i] <= '9' && \
				draw[i + 1] >= '0' && draw[i + 1] <= '9')
			put_room_color(lem, find_room_id(lem, &draw[i]), ants);
		else if (!(draw[i] >= '0' && draw[i] <= '9'))
			printf("%c", draw[i]);
		i++;
	}
}
