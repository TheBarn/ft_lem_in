/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:44:03 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 17:30:48 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int				u_count_digit(unsigned int n)
{
	int				count;

	count = 1;
	while (n > 9)
	{
		n = (n - (n % 10)) / 10;
		count++;
	}
	return (count);
}

char					*ft_utoa(unsigned int n)
{
	char			*dst;
	int				i;
	int				count;

	count = u_count_digit(n);
	dst = ft_strnew(count);
	i = count - 1;
	while (i >= 0)
	{
		dst[i] = n % 10 + 48;
		n = (n - (n % 10)) / 10;
		i--;
	}
	return (dst);
}
