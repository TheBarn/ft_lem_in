/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:23:21 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 11:55:31 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		test_intmax(char *str)
{
	int		diff;

	diff = ft_strcmp(str, "2147483647");
	if (diff > 0)
		return (0);
	return (1);
}

void	is_positive_integer(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (len > 10)
		exit_lem_in("ERROR");
	while (i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit_lem_in("ERROR");
		i++;
	}
	if (len == 10)
		if (!test_intmax(str))
			exit_lem_in("ERROR");
}

int		parse_nb(int fd, char **line)
{
	int		nb;

	nb = -1;
	while (nb == -1 && get_next_line(fd, line) == 1)
	{
		ft_printf("%s\n", *line);
		if ((*line)[0] == '#' && read_command(*line) != 0)
			exit_lem_in("ERROR");
		else
		{
			is_positive_integer(*line);
			nb = ft_atoi(*line);
		}
		free(*line);
	}
	if (nb == -1)
		exit_lem_in("ERROR");
	return (nb);
}
