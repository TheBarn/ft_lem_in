/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:50:15 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 17:24:13 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

int		ft_putstr_special(char *str)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while ((size_t)i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i++;
			else if (str[i + 1] == ' ')
			{
				i++;
				while (str[i] == ' ')
				{
					d++;
					i++;
				}
			}
			d++;
		}
		ft_putchar(str[i++]);
	}
	return (d);
}

int		print_part(const char *format, int start, int end)
{
	char	*str;
	int		i;

	str = ft_strsub(format, start, end - start);
	i = ft_strlen(str);
	i -= ft_putstr_special(str);
	free(str);
	return (i);
}

int		get_value2(t_value value, va_list argp)
{
	int i;

	i = 0;
	if (IS_WSTR || (IS_STR && IS_LONG))
		i += get_wstr(&value, argp);
	else if (IS_PTR)
		i += get_ptr(&value, argp);
	else if (IS_LD || IS_LO || IS_LU || IS_LONG)
		i += get_long(&value, argp);
	else if (IS_LLONG)
		i += get_llong(&value, argp);
	else if (value.conversion != 0)
		i += get_no(&value);
	return (i);
}

int		get_value(t_value value, va_list argp)
{
	int i;

	i = 0;
	if (IS_CHAR && (IS_STR || IS_PTR || IS_INT || IS_O || IS_HEX || IS_U))
		i += get_char(&value, argp);
	else if (IS_INTMAX)
		i += get_imax(&value, argp);
	else if (IS_SIZE_T)
		i += get_size_t(&value, argp);
	else if (IS_SHRT && (IS_STR || IS_PTR || IS_INT || IS_O || IS_HEX || IS_U))
		i += get_short(&value, argp);
	else if ((IS_INT || IS_O || IS_HEX || IS_U) && !IS_LONG && !IS_LLONG)
		i += get_int(&value, argp);
	else if (IS_STR && !IS_LONG)
		i += get_str(&value, argp);
	else
		i += get_value2(value, argp);
	return (i);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list argp;
	int		i;
	int		k;
	int		toto;
	t_value value;

	i = 0;
	k = 0;
	toto = 0;
	va_start(argp, format);
	i = next_arg(format, i);
	while ((size_t)i < ft_strlen(format))
	{
		toto += print_part(format, k, i);
		i = analyze_arg(format, &value, i, argp);
		k = i;
		toto += get_value(value, argp);
		i = next_arg(format, i);
	}
	toto += print_part(format, k, i);
	va_end(argp);
	return (toto);
}
