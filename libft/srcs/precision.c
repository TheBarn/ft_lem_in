/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:44:11 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 13:37:37 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

char	*add_to_the_right(char *str, char c)
{
	char	*new;

	new = ft_strnew(ft_strlen(str) + 2);
	ft_strcat(new, str);
	new[ft_strlen(str)] = c;
	ft_strdel(&str);
	return (new);
}

char	*add_to_the_left(char *str, char c)
{
	char	*new;

	new = ft_strnew(ft_strlen(str) + 2);
	new[0] = c;
	ft_strcat(new, str);
	ft_strdel(&str);
	return (new);
}

char	*add_0_to_the_left(char *str, t_value value)
{
	int		i;
	int		nb;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	nb = value.precision - len;
	while (i < nb)
	{
		str = add_to_the_left(str, '0');
		i++;
	}
	return (str);
}

char	*apply_precision(t_value value, char *str)
{
	char	*tmp;

	if (value.precision == 0 && !(IS_STR || IS_WSTR) && str && str[0] == '0')
		return (NULL);
	if (!is_str_cv(value.conversion))
		str = add_0_to_the_left(str, value);
	else if (value.precision >= 0 && (IS_S || IS_WS || IS_C) && \
								(size_t)value.precision < ft_strlen(str))
	{
		tmp = str;
		str = ft_strnew(value.precision + 1);
		ft_strncpy(str, tmp, value.precision);
	}
	return (str);
}
