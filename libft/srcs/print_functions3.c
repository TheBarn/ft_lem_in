/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:35:34 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 15:09:07 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_str(t_value value)
{
	int		total;
	char	*str;

	str = ft_strdup(value.val.str);
	if (is_cv(value.conversion) == 1)
		str = apply_precision(value, str);
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	free(str);
	return (total);
}

int		print_wchar(char *str, t_value value)
{
	unsigned char	c;
	int				i;
	int				toto;

	i = 0;
	toto = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || (str[i] == '0' && (value.flags)[3] == '0'))
		{
			ft_putchar(str[i]);
			i++;
		}
		else
		{
			c = str_to_hex(&str[i]);
			write(1, &c, 1);
			i += 2;
		}
		toto++;
	}
	return (toto);
}

int		print_wstr(t_value value)
{
	char	*str;
	int		i;
	int		toto;
	int		count_bytes;

	i = 0;
	toto = 0;
	count_bytes = 0;
	str = NULL;
	while (i < ft_wstrlen_t(value.val.wstr))
	{
		count_bytes = wchar_to_bytes(value, i, count_bytes, &str);
		i++;
	}
	str = apply_flags(value, str);
	toto += print_wchar(str, value);
	free(str);
	return (toto);
}

int		print_ptr(t_value value)
{
	int		total;
	char	*str;

	str = ptr_conversion(value);
	str = apply_precision(value, str);
	str = add_to_the_left(str, 'x');
	str = add_to_the_left(str, '0');
	str = apply_flags(value, str);
	ft_putstr(str);
	total = ft_strlen(str);
	free(str);
	return (total);
}
