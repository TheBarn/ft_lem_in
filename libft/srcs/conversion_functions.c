/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:14:09 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 19:04:54 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

char	*char_conversion(t_value value)
{
	char	*str;

	if (IS_INT)
		str = ft_itoa((int)value.val.c);
	if (IS_O)
		str = conversion((unsigned int)value.val.uc, 8);
	if (IS_HEX)
		str = conversion((int)value.val.uc, 16);
	if (IS_U)
		str = ft_utoa((unsigned int)value.val.uc);
	return (str);
}

char	*short_conversion(t_value value)
{
	char	*str;

	if (IS_INT)
		str = ft_itoa(value.val.shrt);
	if (IS_O)
		str = shrtconversion(value.val.ushrt, 8);
	if (IS_HEX)
		str = shrtconversion(value.val.ushrt, 16);
	if (IS_U)
		str = ft_utoa(value.val.ushrt);
	return (str);
}

char	*int_conversion(t_value value)
{
	char	*str;

	if (IS_INT)
		str = ft_itoa(value.val.nb);
	if (IS_O)
		str = conversion(value.val.u, 8);
	if (IS_HEX)
		str = conversion(value.val.u, 16);
	if (IS_U)
		str = ft_utoa(value.val.u);
	return (str);
}

char	*ptr_conversion(t_value value)
{
	char	*str;

	str = NULL;
	if (value.val.ptr == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
		address_conversion(value.val.ptr, &str);
	return (str);
}
