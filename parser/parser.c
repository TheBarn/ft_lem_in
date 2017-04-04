/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:23:36 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 12:23:40 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_lem_in(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

int		read_command(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	else
		return (0);
}

t_lem	parser(int fd)
{
	char	*line;
	t_lem	lem;

	line = NULL;
	lem.nb = parse_nb(fd, &line);
	lem.size = 0;
	lem.room = parse_room(fd, &lem, &line);
	lem.map = parse_tubes(fd, &lem, &line);
	printf("\n");
	return (lem);
}
