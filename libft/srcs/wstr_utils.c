/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:35:34 by barnout           #+#    #+#             */
/*   Updated: 2017/02/27 16:06:41 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_wstrlen_t(wchar_t *wstr_t)
{
	int		i;

	i = 0;
	if (wstr_t == NULL)
		return (0);
	while (wstr_t[i] != 0)
		i++;
	return (i);
}

char			*justify_zeros(char *small)
{
	int		i;
	char	*new;

	i = 0;
	while (small[i] == '0')
		i++;
	new = ft_strdup(&small[i]);
	ft_strdel(&small);
	return (new);
}

char			*add_zeros(char *small, int nb)
{
	int		len;
	char	*new;
	int		i;
	int		j;

	len = ft_strlen(small);
	new = ft_strnew(nb);
	i = 0;
	while (i < nb - len)
	{
		new[i] = '0';
		i++;
	}
	j = 0;
	while (i < nb)
	{
		new[i] = small[j];
		i++;
		j++;
	}
	ft_strdel(&small);
	return (new);
}

static char		*fill_bits2(int len, char *big, char *small)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_strnew(len);
	while (i < len)
	{
		if (big[i] == 'x')
		{
			new[i] = small[j];
			j++;
		}
		else
			new[i] = big[i];
		i++;
	}
	return (new);
}

char			*fill_bits(char *big, char *small)
{
	int		i;
	int		j;
	int		big_len;
	char	*new;

	i = 0;
	j = 0;
	big_len = ft_strlen(big);
	while (i < big_len)
	{
		if (big[i] == 'x')
			j++;
		i++;
	}
	small = add_zeros(small, j);
	new = fill_bits2(big_len, big, small);
	ft_strdel(&big);
	ft_strdel(&small);
	return (new);
}
