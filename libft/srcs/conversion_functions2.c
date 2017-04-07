/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:50:50 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 17:32:11 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/define.h"

char	*long_conversion(t_value value)
{
	char	*str;

	str = NULL;
	if (IS_LD || IS_INT)
		str = ft_imaxtoa(value.val.lg);
	else if (IS_OCT)
		str = jconversion(value.val.ul, 8);
	else if (IS_UNSG)
		str = ft_uimaxtoa(value.val.ul);
	else if (IS_HEX)
		str = jconversion(value.val.ul, 16);
	return (str);
}

char	*llong_conversion(t_value value)
{
	char	*str;

	str = NULL;
	if (IS_LD || IS_INT)
		str = ft_imaxtoa(value.val.llg);
	else if (IS_OCT)
		str = jconversion(value.val.ull, 8);
	else if (IS_UNSG)
		str = ft_uimaxtoa(value.val.ull);
	else if (IS_HEX)
		str = jconversion(value.val.ull, 16);
	return (str);
}

char	*size_t_conversion(t_value value)
{
	char	*str;

	str = NULL;
	if (IS_LD || IS_INT)
		str = ft_uimaxtoa(value.val.z);
	else if (IS_OCT)
		str = jconversion(value.val.z, 8);
	else if (IS_UNSG)
		str = ft_uimaxtoa(value.val.z);
	else if (IS_HEX)
		str = jconversion(value.val.z, 16);
	return (str);
}

char	*imax_conversion(t_value value)
{
	char	*str;

	str = NULL;
	if (IS_LD || IS_INT)
		str = ft_imaxtoa(value.val.j);
	else if (IS_OCT)
		str = jconversion(value.val.uj, 8);
	else if (IS_UNSG)
		str = ft_uimaxtoa(value.val.uj);
	else if (IS_HEX)
		str = jconversion(value.val.uj, 16);
	return (str);
}
