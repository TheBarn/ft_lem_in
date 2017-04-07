/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:00:46 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 17:30:38 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

void		apply_flag_h(t_value value, char **str)
{
	if (IS_OCT && (*str == NULL || *str[0] != '0'))
		*str = add_to_the_left(*str, '0');
	else if (IS_HEX && *str && ft_strcmp(*str, "0") != 0)
	{
		*str = add_to_the_left(*str, 'x');
		*str = add_to_the_left(*str, '0');
	}
}

static int	ini_len(t_value value, char *str)
{
	int		len;

	if (IS_WSTR)
		len = ft_strlen(str) / 2;
	else
		len = ft_strlen(str);
	if (IS_C)
		len = 1;
	return (len);
}

char		*apply_flags(t_value value, char *str)
{
	char	padding;
	int		len;

	padding = ' ';
	if (value.flags[4] == '#')
		apply_flag_h(value, &str);
	if ((value.flags)[3] == '0' && (value.flags)[0] != '-')
		padding = '0';
	len = ini_len(value, str);
	apply_flag_p(value, &str, padding, len);
	if ((value.flags)[2] == ' ' && (value.flags)[1] == '.' \
			&& str && str[0] != '-' && IS_INT)
		str = add_to_the_left(str, ' ');
	if (((value.flags)[3] == '0' || value.precision > -1) \
			&& is_str_cv(value.conversion) == 0)
		str = swap_minus(str);
	return (str);
}
