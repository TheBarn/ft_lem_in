/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:25:48 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 11:55:55 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_words(char *s, char c)
{
	int		i;
	int		toto;
	int		count;
	char	c2;

	i = 0;
	count = 0;
	toto = 0;
	c2 = c;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			toto++;
			i++;
		}
		if (toto != 0)
			count++;
		toto = 0;
	}
	return (count);
}

int		is_integer(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len > 10)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (len == 10 && !test_intmax(str))
		return (0);
	return (1);
}

void	free_split(char **tab, int size)
{
	int		i;

	i = 0;
	while (i <= size)
		free(tab[i++]);
	free(tab);
}

void	fill_new_room(t_room *room, char **split, int tmp)
{
	room->name = ft_strdup(split[0]);
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->sp = tmp;
}
