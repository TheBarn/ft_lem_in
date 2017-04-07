/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:44:03 by barnout           #+#    #+#             */
/*   Updated: 2016/11/27 18:24:47 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int				count_digit(int n)
{
	int				count;
	unsigned int	nb;

	count = 1;
	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	while (nb > 9)
	{
		nb = (nb - (nb % 10)) / 10;
		count++;
	}
	return (count);
}

static unsigned int		cast(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	return (nb);
}

char					*ft_itoa(int n)
{
	char			*dst;
	int				toto;
	unsigned int	nb;
	int				i;
	int				count;

	toto = 0;
	if (n < 0)
		toto = 1;
	count = count_digit(n);
	dst = (char *)malloc(count + toto + 1);
	if (dst == NULL)
		return (NULL);
	i = toto + count - 1;
	nb = cast(n);
	while (i >= toto)
	{
		dst[i] = nb % 10 + 48;
		nb = (nb - (nb % 10)) / 10;
		i--;
	}
	if (toto == 1)
		dst[0] = '-';
	dst[count + toto] = '\0';
	return (dst);
}
