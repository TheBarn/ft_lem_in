/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:08 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:19:06 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_tube_between(char *str, int width, t_coord r, t_coord t)
{
	if (r.x == t.x)
	{
		if (r.y > t.y)
			put_tube_between(str, width, t, r);
		else
			put_vertical(str, width, r.x, r.y);
	}
	else if (r.x > t.x)
		put_tube_between(str, width, t, r);
	else
	{
		if (r.y == t.y)
			put_horizontal(str, width, r.x, r.y);
		else if (r.y > t.y)
			put_up(str, width, r.x, r.y);
		else
			put_down(str, width, r.x, r.y);
	}
}

void	put_tube(char *str, int width, char *n1, char *n2)
{
	int		a;
	t_coord	r;
	t_coord	t;

	a = 0;
	while ((size_t)a < ft_strlen(str) && ft_strncmp(&str[a], n1, 2))
		a++;
	r.x = a % width;
	r.y = a / width;
	a = 0;
	while ((size_t)a < ft_strlen(str) && ft_strncmp(&str[a], n2, 2))
		a++;
	t.x = a % width;
	t.y = a / width;
	put_tube_between(str, width, r, t);
}

void	put_tubes(t_lem lem, char *str, char **path, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < lem.size)
	{
		j = 0;
		while (j < lem.size)
		{
			if (path[i][j] == 1 && j != 0)
				put_tube(str, width, lem.room[i].name, lem.room[j].name);
			j++;
		}
		i++;
	}
}
