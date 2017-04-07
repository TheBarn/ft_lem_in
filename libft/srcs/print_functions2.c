/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:35:30 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 11:24:04 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_long(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = long_conversion(value);
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

int		print_llong(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = llong_conversion(value);
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

int		print_size_t(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = size_t_conversion(value);
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

int		print_imax(t_value value)
{
	int		total;
	char	*str;
	char	*tmp;

	str = imax_conversion(value);
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
