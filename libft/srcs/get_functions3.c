/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:21:13 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 11:32:08 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_no(t_value *value)
{
	int		i;

	i = 0;
	value->val.str = ft_strnew(2);
	value->val.str[0] = value->conversion;
	i += print_str(*value);
	free(value->val.str);
	return (i);
}
