/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:27:33 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 18:14:48 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	swap_minus2(char **new, char *str, char *toto)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[len - 1 - i] != '-' && str[len - 1 - i] != 'x')
		{
			(*new)[len - 1 - i] = str[len - 1 - i];
		}
		else
		{
			if (len - 2 - i >= 0 && str[len - 2 - i] == '0')
			{
				(*new)[len - 1 - i] = '0';
				*toto = str[len - 1 - i];
			}
			else
				(*new)[len - 1 - i] = str[len - 1 - i];
		}
		i++;
	}
}

char		*swap_minus(char *str)
{
	char	*new;
	int		i;
	char	toto;
	int		len;

	i = 0;
	toto = 0;
	len = ft_strlen(str);
	new = ft_strnew(len);
	swap_minus2(&new, str, &toto);
	if (toto)
	{
		i = 0;
		while (new[i] != '0' && i < len)
			i++;
		if (toto == 'x')
			i++;
		new[i] = toto;
	}
	free(str);
	return (new);
}
