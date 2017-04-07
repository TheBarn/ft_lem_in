/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:45:52 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 11:22:21 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_char(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = char_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
	{
		tmp = str;
		str = toupper_str(str);
		free(tmp);
	}
	ft_putstr(str);
	total = ft_strlen(str);
	free(str);
	return (total);
}

int		print_short(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = short_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
	{
		tmp = str;
		str = toupper_str(str);
		free(tmp);
	}
	ft_putstr(str);
	total = ft_strlen(str);
	free(str);
	return (total);
}

int		print_int(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = int_conversion(value);
	str = apply_precision(value, str);
	str = apply_flags(value, str);
	if (value.conversion == 'X')
	{
		tmp = str;
		str = toupper_str(str);
		free(tmp);
	}
	ft_putstr(str);
	total = ft_strlen(str);
	free(str);
	return (total);
}
