/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:19:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 16:05:36 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

int		get_size_t(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	value->val.z = va_arg(argp, size_t);
	if (value->val.z > LLONG_MAX && !AS_UNSG && !AS_OCT && !AS_HEX)
	{
		value->val.j = LLONG_MIN;
		i += print_imax(*value);
	}
	else
		i += print_size_t(*value);
	return (i);
}

int		get_imax(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_UNSG || AS_OCT || AS_HEX)
		value->val.uj = va_arg(argp, uintmax_t);
	else
		value->val.j = va_arg(argp, intmax_t);
	i += print_imax(*value);
	return (i);
}

int		get_str(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_S)
	{
		value->val.str = va_arg(argp, char *);
		if (value->val.str == NULL)
			value->val.str = "(null)";
	}
	if (AS_C)
	{
		value->val.str = ft_strnew(2);
		value->val.str[0] = (char)va_arg(argp, int);
	}
	i += print_str(*value);
	if (value->val.str[0] == 0 && AS_C)
	{
		ft_putchar('\0');
		i++;
	}
	if (AS_C)
		free(value->val.str);
	return (i);
}

int		get_wstr(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	if (AS_WS || AS_S)
	{
		value->val.wstr = va_arg(argp, wchar_t *);
		if (value->val.wstr == NULL)
			value->val.wstr = L"(null)";
	}
	if (AS_WC || AS_C)
	{
		value->val.wstr = (int *)malloc(2 * sizeof(int));
		value->val.wstr[0] = (int)va_arg(argp, int);
		value->val.wstr[1] = 0;
		if (value->val.wstr[0] == 0)
		{
			ft_putchar('\0');
			i++;
		}
	}
	i += print_wstr(*value);
	if (AS_WC || AS_C)
		free(value->val.wstr);
	return (i);
}

int		get_ptr(t_value *value, va_list argp)
{
	int		i;

	i = 0;
	value->val.ptr = (unsigned long)va_arg(argp, void *);
	i += print_ptr(*value);
	return (i);
}
