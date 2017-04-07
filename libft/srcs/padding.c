/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:24:10 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 17:19:14 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

static void	left_padding(t_value value, char **str, char *padding, int diff)
{
	int	i;

	i = 0;
	if ((*padding == '0' && ((value.flags[1] == '+' \
						&& !str_is_neg(*str)))) || value.flags[2] == ' ')
		i++;
	if (is_int_cv(value.conversion) && value.precision != -1)
	{
		while (i < value.precision - (int)ft_strlen(*str))
		{
			*str = add_to_the_left(*str, *padding);
			i++;
		}
		*padding = ' ';
	}
	while (i < diff)
	{
		*str = add_to_the_left(*str, *padding);
		i++;
	}
}

static char	*add_padding(t_value value, char *str, char padding, int len)
{
	int		diff;
	int		i;

	i = 0;
	diff = value.width - len;
	if ((padding == '0' && ((value.flags[1] == '+' \
						&& !str_is_neg(str)))) || value.flags[2] == ' ')
		i++;
	if ((value.flags)[0] == '.')
		left_padding(value, &str, &padding, diff);
	if ((value.flags)[0] == '-')
	{
		while (i < diff)
		{
			str = add_to_the_right(str, padding);
			i++;
		}
	}
	return (str);
}

void		apply_flag_p(t_value value, char **str, char padding, int len)
{
	int		toto;

	toto = 0;
	if ((value.flags)[1] == '+' && padding == ' ' && \
			*str && !str_is_neg(*str) && (IS_INT || IS_LD))
	{
		*str = add_to_the_left(*str, '+');
		toto = 1;
		len++;
	}
	if (value.width > len)
		*str = add_padding(value, *str, padding, len);
	if ((value.flags)[1] == '+' && toto == 0 && \
			*str && !str_is_neg(*str) && (IS_INT || IS_LD))
		*str = add_to_the_left(*str, '+');
}
