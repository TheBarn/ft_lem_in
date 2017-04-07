/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:45:56 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 11:53:42 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

int		add_to_left(char **left, int fd)
{
	char	*tmp;
	char	*buf;
	int		count;

	buf = ft_strnew(BUFF_SIZE + 1);
	count = read(fd, buf, BUFF_SIZE);
	if (count <= 0)
	{
		free(buf);
		return (count);
	}
	tmp = *left;
	*left = ft_strnew(ft_strlen(*left) + count + 1);
	*left = ft_strcpy(*left, tmp);
	*left = ft_strcat(*left, buf);
	free(tmp);
	free(buf);
	return (count);
}

int		read_again(char **left)
{
	int		toto;
	int		i;

	toto = 0;
	i = 0;
	while ((*left)[i] != '\n' && (*left)[i] != '\0')
		i++;
	if ((*left)[i] == '\n')
		return (0);
	return (1);
}

char	*truncate_left(char **left)
{
	int		len;
	char	*line;
	char	*tmp;

	len = 0;
	while ((*left)[len] != '\n')
		len++;
	tmp = *left;
	line = ft_strsub(*left, 0, len);
	*left = ft_strsub(*left, len + 1, ft_strlen(*left) - len);
	if (ft_strlen(*left) == 0)
	{
		free(*left);
		*left = NULL;
	}
	free(tmp);
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static char *left = NULL;
	int			count;
	int			toto;

	toto = 0;
	if (line == NULL)
		return (-1);
	if (left == NULL)
		left = ft_strnew(1);
	while (read_again(&left))
	{
		toto++;
		if ((count = add_to_left(&left, fd)) == -1)
			return (-1);
		if (count == 0)
		{
			*line = left;
			if (toto > 1)
				return (1);
			return (0);
		}
	}
	*line = truncate_left(&left);
	return (1);
}
