/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:33:31 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 16:10:43 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_int_cv(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'o')
		return (1);
	return (0);
}

int		is_str_cv(char c)
{
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		is_cv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'x' \
			|| c == 'X' || c == 'o' || c == 'O' || c == 's' || c == 'S' \
			|| c == 'c' || c == 'C' || c == 'p')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int		str_is_neg(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '-')
		return (1);
	return (0);
}
