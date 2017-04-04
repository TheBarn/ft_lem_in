/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:38:39 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 12:38:45 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_rooms_order(t_lem lem)
{
	int		i;

	i = 0;
	while (i < lem.size)
	{
		printf("room[%d] is %s\n", i, ((lem.room[i]).name));
		i++;
	}
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(tab[size - 1]);
	ft_putchar('\n');
}

int		*ft_tabcpy(int *tab, int size)
{
	int		i;
	int		*new;

	new = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
