/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:50:54 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 17:29:10 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

int		analyze_arg(const char *format, t_value *value, int i, va_list argp)
{
	i++;
	i = put_flags(format, value, i);
	i = put_width(format, value, i, argp);
	i = put_precision(format, value, i, argp);
	i = put_modifier(format, value, i);
	value->conversion = format[i];
	if (format[i] != '\0')
		i++;
	return (i);
}

int		next_arg(const char *format, int i)
{
	int		k;

	if (format == NULL || format[0] == '\0')
		return (0);
	while (format[i] != '%' || (format[i] == '%' && GO_NEXT))
	{
		if (format[i] == '\0')
			return (i);
		else if (format[i + 1] == '\0')
			return (i + 1);
		else if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1] == ' ')
		{
			k = 1;
			while (format[i + k] == ' ')
				k++;
			if (format[i + k] == '%')
				i = i + k;
			else
				return (i);
		}
		i++;
	}
	return (i);
}
