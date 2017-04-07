/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:28:31 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 17:30:59 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

int		get_char(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_U || AS_O || AS_HEX)
		value->val.uc = (unsigned char)va_arg(argp, int);
	else
		value->val.c = (char)va_arg(argp, int);
	i += print_char(*value);
	return (i);
}

int		get_short(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_UNSG || AS_OCT || AS_HEX)
		value->val.ushrt = va_arg(argp, unsigned int);
	else
		value->val.shrt = va_arg(argp, int);
	i += print_short(*value);
	return (i);
}

int		get_int(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_UNSG || AS_OCT || AS_HEX)
		value->val.u = va_arg(argp, unsigned int);
	else
		value->val.nb = va_arg(argp, int);
	i += print_int(*value);
	return (i);
}

int		get_long(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_UNSG || AS_OCT || AS_HEX)
		value->val.ul = va_arg(argp, unsigned long);
	else
		value->val.lg = va_arg(argp, long);
	i += print_long(*value);
	return (i);
}

int		get_llong(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_UNSG || AS_OCT || AS_HEX)
		value->val.ull = va_arg(argp, unsigned long long);
	else
		value->val.llg = va_arg(argp, long long);
	i += print_llong(*value);
	return (i);
}
