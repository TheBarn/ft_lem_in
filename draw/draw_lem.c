/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:42:26 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:24:13 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		max_x(t_lem lem)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (i < lem.size)
		max = ft_max(max, lem.room[i++].x);
	return (max + 3);
}

int		max_y(t_lem lem)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (i < lem.size)
		max = ft_max(max, lem.room[i++].y);
	return (max + 1);
}

void	put_room(t_lem lem, char *str, int width)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < lem.size)
	{
		x = lem.room[i].x;
		y = lem.room[i].y;
		str[x + width * y] = (lem.room[i].name)[0];
		str[x + width * y + 1] = (lem.room[i].name)[1];
		i++;
	}
}

char	*ini_str(int width, int length)
{
	char	*str;
	int		len;
	int		i;

	len = width * length;
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		if ((i + 1) % width == 0)
			str[i] = '\n';
		else
			str[i] = '.';
		i++;
	}
	return (str);
}

char	*draw_lem(t_lem lem, char **tubes)
{
	int		width;
	int		length;
	char	*str;

	width = max_x(lem);
	length = max_y(lem);
	str = ini_str(width, length);
	put_room(lem, str, width);
	put_tubes(lem, str, tubes, width);
	return (str);
}
