/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:47:56 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 15:35:24 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*shrtconversion(unsigned short nb, int base)
{
	char	*str;
	int		rem;

	str = ft_strnew(1);
	rem = -1;
	if (nb == 0)
	{
		free(str);
		str = ft_strdup("0");
	}
	while (nb != 0)
	{
		rem = nb % base;
		nb /= base;
		if (rem < 10)
			str = add_to_the_left(str, '0' + rem);
		if (rem > 9)
			str = add_to_the_left(str, 'a' + rem - 10);
	}
	return (str);
}

char	*conversion(unsigned int nb, int base)
{
	char	*str;
	int		rem;

	str = ft_strnew(1);
	rem = -1;
	if (nb == 0)
	{
		free(str);
		str = ft_strdup("0");
	}
	while (nb != 0)
	{
		rem = nb % base;
		nb /= base;
		if (rem < 10)
			str = add_to_the_left(str, '0' + rem);
		if (rem > 9)
			str = add_to_the_left(str, 'a' + rem - 10);
	}
	return (str);
}

char	*jconversion(uintmax_t nb, int base)
{
	char	*str;
	int		rem;

	str = ft_strnew(1);
	rem = -1;
	if (nb == 0)
	{
		free(str);
		str = ft_strdup("0");
	}
	while (nb != 0)
	{
		rem = nb % base;
		nb /= base;
		if (rem < 10)
			str = add_to_the_left(str, '0' + rem);
		if (rem > 9)
			str = add_to_the_left(str, 'a' + rem - 10);
	}
	return (str);
}

void	address_conversion(unsigned long ptr, char **str)
{
	char digit;

	digit = ptr % 16;
	if (ptr > 0)
		address_conversion(ptr / 16, str);
	if (digit < 10 && ptr != 0)
		*str = add_to_the_right(*str, '0' + digit);
	else if (ptr != 0)
		*str = add_to_the_right(*str, 'a' + digit - 10);
}
