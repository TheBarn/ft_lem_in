/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:05:33 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 19:37:32 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_middle_ants(t_lem lem, int *ants, char *str)
{
	int		ant;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		while (str[i] != 'L')
			i++;
		ant = ft_atoi(&str[++i]);
		while (str[i] != '-')
			i++;
		if (find_room_id(lem, &str[++i]) != lem.size - 1)
			ants[find_room_id(lem, &str[i])] = ant;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
}

int		nb_last_room(char *line, char *str)
{
	int		toto;
	int		i;

	i = 0;
	toto = 0;
	while (line[i] != '\0' && line[i + 1] != '\0' && line[i + 2] != '\0')
	{
		if (line[i] == str[0] && line[i + 1] == str[1] && line[i + 2] == str[2])
			toto++;
		i++;
	}
	return (toto);
}

int		count_last_room(t_lem lem, char *line)
{
	char	*str;
	int		nb;

	str = ft_strnew(3);
	str[0] = '-';
	str = ft_strcat(str, lem.room[lem.size - 1].name);
	nb = nb_last_room(line, str);
	free(str);
	return (nb);
}

void	clear_middle(int size, int *ants)
{
	int		i;

	i = 1;
	while (i < size - 1)
		ants[i++] = 0;
}

void	move_ants(t_lem lem, char *str)
{
	char	*line;
	int		ants[lem.size];
	int		toto;
	int		len;

	line = NULL;
	len = max_y(lem);
	ini_ants(lem, ants);
	print_path_color(lem, str, ants);
	toto = 0;
	while (get_next_line(0, &line) == 1 && line[0] != '\0')
	{
		sleep(1);
		if (toto == 0)
		{
			sleep(1);
			toto = ft_strcount(line, ' ') + 1;
		}
		ants[0] = ft_max(ants[0] - toto, 0);
		add_middle_ants(lem, ants, line);
		ants[lem.size - 1] += count_last_room(lem, line);
		ft_printf("\e[%dA", len);
		print_path_color(lem, str, ants);
		clear_middle(lem.size, ants);
		free(line);
	}
	free(line);
}
