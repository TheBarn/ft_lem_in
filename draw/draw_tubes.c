/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:08 by barnout           #+#    #+#             */
/*   Updated: 2017/03/30 17:56:50 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_vertical(char *str, int width, int x1, int y1)
{
	str[x1 + width * (y1 + 1)] = '|';
	str[x1 + width * (y1 + 2)] = '|';
	str[x1 + width * (y1 + 3)] = '|';
}

void	put_horizontal(char *str, int width, int x1, int y1)
{
	str[x1 + 2 + width * y1] = '-';
	str[x1 + 3 + width * y1] = '-';
	str[x1 + 4 + width * y1] = '-';
}

void	put_up(char *str, int width, int x1, int y1)
{
	str[x1 + 2 + width * (y1 - 1)] = '/';
	str[x1 + 3 + width * (y1 - 2)] = '/';
	str[x1 + 4 + width * (y1 - 3)] = '/';
}

void	put_down(char *str, int width, int x1, int y1)
{
	str[x1 + 2 + width * (y1 + 1)] = '\\';
	str[x1 + 3 + width * (y1 + 2)] = '\\';
	str[x1 + 4 + width * (y1 + 3)] = '\\';
}

void	put_tube_between(char *str, int width, int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		if (y1 > y2)
			put_tube_between(str, width, x2, y2, x1, y1);
		else
			put_vertical(str, width, x1, y1);
	}
	else if (x1 > x2)
		put_tube_between(str, width, x2, y2, x1, y1);
	else
	{
		if (y1 == y2)
			put_horizontal(str, width, x1, y1);
		else if (y1 > y2)
			put_up(str, width, x1, y1);
		else
			put_down(str, width, x1, y1);
	}
}

void	put_tube(t_lem *lem, char *str, int width, int i, int j)
{
	int		a;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	a = 0;
//	printf("tube %s-%s\n", ROOM[i].name, ROOM[j].name);
	while ((size_t) a < ft_strlen(str) && (str[a] != (ROOM[i].name)[0] || str[a + 1] != (ROOM[i].name)[1]))
		a++;
	x1 = a % width;
	y1 = a / width;
	a = 0;
	while ((size_t) a < ft_strlen(str) && str[a] != j + (ROOM[j].name)[0] && str[a + 1] != (ROOM[j].name)[1])
		a++;
	x2 = a % width;
	y2 = a / width;
//	printf("i is %d [%d|%d] and j is %d [%d|%d]\n", i, x1, y1, j, x2, y2);
	put_tube_between(str, width, x1, y1, x2, y2);
}

void	put_tubes(t_lem *lem, char *str, char **path, int width, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (path[i][j] == 1 && j != 0)
				put_tube(lem, str, width, i, j);
			j++;
		}
		i++;
	}
}
