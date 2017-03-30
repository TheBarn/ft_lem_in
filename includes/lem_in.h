/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:52:57 by barnout           #+#    #+#             */
/*   Updated: 2017/03/30 18:29:55 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>


typedef struct 	s_room
{
	char	*name;
	int		x;
	int		y;
	int		sp;
}				t_room;

typedef struct	s_tube
{
	int		start;
	int		end;
}				t_tube;

typedef struct	s_lem
{
	int		nb;
	int		size;
	t_room	*room;
	char	**map;
}				t_lem;

typedef struct	s_path
{
	char	***path;
	int		size;
}				t_path;

int		parse_nb(int fd, char **line);
int		test_intmax(char *str);
t_room	*parse_room(int fd, t_lem *lem, char **line);
int		count_words(char *s, char c);
char	**parse_tubes(int fd, t_lem *lem, char **line);
t_lem	parser(int fd);
void	exit_lem_in(char *str);
int		read_command(char *line);
void	free_split(char **tab, int size);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*draw_lem(t_lem *lem, char **tube);
t_path	algo(char **lem, int size);
void	print_lem(char **lem, int size); //
char	**ft_lemcpy(char **lem, int size);
void	move_ants(t_path slt, int nb, int size, char *draw);
char	**ini_path(int size);
void	free_path(char **path, int size);
void	add_paths(t_path slt, int size, char **com);
void	print_tab(int *tab, int size);
void	put_in_order(t_lem *lem);
void	put_tubes(t_lem *lem, char *str, char **path, int width, int size);
void	print_rooms_order(t_lem lem);

# define ROOM (lem->room)
# define SIZE (lem->size)
# define NB (lem->nb)
# define MAP (lem->map)
# define BUFF_SIZE 8

#endif
