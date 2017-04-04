/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:17:19 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:18:59 by barnout          ###   ########.fr       */
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
