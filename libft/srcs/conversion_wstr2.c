/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_wstr2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:09:32 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 16:20:07 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*binary_conversion(char *hex)
{
	char	*str;
	char	*dom;
	char	*tmp;
	int		i;

	str = NULL;
	i = 0;
	while (hex != NULL && hex[i] != '\0')
	{
		dom = hex_to_binary(hex[i]);
		tmp = str;
		str = ft_strjoin(str, dom);
		ft_strdel(&dom);
		ft_strdel(&tmp);
		i++;
	}
	ft_strdel(&hex);
	return (str);
}

static char		*utf8_conversion(char *small)
{
	char	*big;
	char	*new;
	int		bits;
	char	*dom;
	int		i;

	small = justify_zeros(small);
	bits = ft_strlen(small);
	big = bits_canvas(bits);
	big = fill_bits(big, small);
	new = NULL;
	i = 0;
	while (big[i] != '\0')
	{
		dom = binary_to_hex(&big[i]);
		new = add_to_the_right(new, *dom);
		ft_strdel(&dom);
		i += 4;
	}
	ft_strdel(&big);
	return (new);
}

static void		str_to_hex2(char *str, unsigned char *c)
{
	if (str[1] == 'a')
		*c += 10;
	else if (str[1] == 'b')
		*c += 11;
	else if (str[1] == 'c')
		*c += 12;
	else if (str[1] == 'd')
		*c += 13;
	else if (str[1] == 'e')
		*c += 14;
	else if (str[1] == 'f')
		*c += 15;
	else
		*c += (str[1] - '0');
}

unsigned char	str_to_hex(char *str)
{
	unsigned char	c;

	c = 0;
	if (str[0] == 'a')
		c += 16 * 10;
	else if (str[0] == 'b')
		c += 16 * 11;
	else if (str[0] == 'c')
		c += 16 * 12;
	else if (str[0] == 'd')
		c += 16 * 13;
	else if (str[0] == 'e')
		c += 16 * 14;
	else if (str[0] == 'f')
		c += 16 * 15;
	else
		c += 16 * (str[0] - '0');
	str_to_hex2(str, &c);
	return (c);
}

int				wchar_to_bytes(t_value value, int i, \
								int count_bytes, char **str)
{
	char	*new;
	char	*big;

	new = conversion(value.val.wstr[i], 16);
	new = binary_conversion(new);
	new = utf8_conversion(new);
	count_bytes += ft_strlen(new) / 2;
	if (value.precision == -1 || count_bytes <= value.precision)
	{
		big = ft_strjoin(*str, new);
		ft_strdel(str);
		*str = big;
	}
	ft_strdel(&new);
	return (count_bytes);
}
