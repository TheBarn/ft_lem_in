/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:09:25 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 16:09:57 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*bits_canvas(int bits)
{
	char	*big;

	if (bits > 0 && bits < 8)
		big = ft_strdup("0xxxxxxx");
	if (bits > 7 && bits < 12)
		big = ft_strdup("110xxxxx10xxxxxx");
	if (bits > 11 && bits < 17)
		big = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	if (bits > 16 && bits < 22)
		big = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	return (big);
}

static char		*hex_to_binary2(char h)
{
	char	*str;

	if (h == '8')
		str = ft_strdup("1000");
	else if (h == '9')
		str = ft_strdup("1001");
	else if (h == 'a')
		str = ft_strdup("1010");
	else if (h == 'b')
		str = ft_strdup("1011");
	else if (h == 'c')
		str = ft_strdup("1100");
	else if (h == 'd')
		str = ft_strdup("1101");
	else if (h == 'e')
		str = ft_strdup("1110");
	else if (h == 'f')
		str = ft_strdup("1111");
	else
		str = ft_strdup("0000");
	return (str);
}

char			*hex_to_binary(char h)
{
	char	*str;

	if (h == '0')
		str = ft_strdup("0000");
	else if (h == '1')
		str = ft_strdup("0001");
	else if (h == '2')
		str = ft_strdup("0010");
	else if (h == '3')
		str = ft_strdup("0011");
	else if (h == '4')
		str = ft_strdup("0100");
	else if (h == '5')
		str = ft_strdup("0101");
	else if (h == '6')
		str = ft_strdup("0110");
	else if (h == '7')
		str = ft_strdup("0111");
	else
		str = hex_to_binary2(h);
	return (str);
}

static void		binary_to_hex2(char *bi, char **c)
{
	if (ft_strncmp(bi, "1000", 4) == 0)
		*c = ft_memcpy(*c, "8", 1);
	else if (ft_strncmp(bi, "1001", 4) == 0)
		*c = ft_memcpy(*c, "9", 1);
	else if (ft_strncmp(bi, "1010", 4) == 0)
		*c = ft_memcpy(*c, "a", 1);
	else if (ft_strncmp(bi, "1011", 4) == 0)
		*c = ft_memcpy(*c, "b", 1);
	else if (ft_strncmp(bi, "1100", 4) == 0)
		*c = ft_memcpy(*c, "c", 1);
	else if (ft_strncmp(bi, "1101", 4) == 0)
		*c = ft_memcpy(*c, "d", 1);
	else if (ft_strncmp(bi, "1110", 4) == 0)
		*c = ft_memcpy(*c, "e", 1);
	else if (ft_strncmp(bi, "1111", 4) == 0)
		*c = ft_memcpy(*c, "f", 1);
	else
		*c = ft_memcpy(*c, "0", 1);
}

char			*binary_to_hex(char *bi)
{
	char	*c;

	c = ft_strnew(2);
	if (ft_strncmp(bi, "0000", 4) == 0)
		c = ft_memcpy(c, "0", 1);
	else if (ft_strncmp(bi, "0001", 4) == 0)
		c = ft_memcpy(c, "1", 1);
	else if (ft_strncmp(bi, "0010", 4) == 0)
		c = ft_memcpy(c, "2", 1);
	else if (ft_strncmp(bi, "0011", 4) == 0)
		c = ft_memcpy(c, "3", 1);
	else if (ft_strncmp(bi, "0100", 4) == 0)
		c = ft_memcpy(c, "4", 1);
	else if (ft_strncmp(bi, "0101", 4) == 0)
		c = ft_memcpy(c, "5", 1);
	else if (ft_strncmp(bi, "0110", 4) == 0)
		c = ft_memcpy(c, "6", 1);
	else if (ft_strncmp(bi, "0111", 4) == 0)
		c = ft_memcpy(c, "7", 1);
	else
		binary_to_hex2(bi, &c);
	return (c);
}
