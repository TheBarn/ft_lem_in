/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:52:57 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 18:38:37 by barnout          ###   ########.fr       */
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

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

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
char	**parse_tubes(int fd, t_lem *lem, char **line, int opt);
t_lem	parser(int opt);
void	exit_lem_in(char *str);
int		read_command(char *line);
void	free_split(char **tab, int size);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*draw_lem(t_lem lem, char **tube);
t_path	algo(char **lem, int size);
void	print_lem(char **lem, int size); //
char	**ft_lemcpy(char **lem, int size);
void	move_ants(t_lem lem, char *draw);
char	**ini_path(int size);
void	free_path(char **path, int size);
void	add_paths(t_path slt, int size, char **com);
void	print_tab(int *tab, int size);
void	put_tubes(t_lem lem, char *str, char **path, int width);
void	print_rooms_order(t_lem lem);
void	draw_from_path(t_lem lem, char **path, char *draw, int nb_slt);
void	exc_paths(t_lem lem, char *draw);
void	check_path(int size);
int		max_y(t_lem lem);
int		find_room_id(t_lem lem, char *str);
void	print_path_color(t_lem lem, char *draw, int *ants);
void	ft_putroom_in_color(int room, int color);
void	move_ants_no_show(t_lem lem, t_path slt);
void	print_mv(int ant, char *room);
void	print_mv_l(int ant, char *room);
int		prune_lem(char **lem, char **path, int size);
char	**prune_path(char **path, int size, int *room);
void	add_new_path(t_path *slt, char **new, int size);
char	**find_shortest_path(t_lem lem);
int		*ft_tabcpy(int *tab, int size);
int		count_words(char *s, char c);
int		is_integer(char *str);
void	free_split(char **tab, int size);
void	fill_new_room(t_room *room, char **split, int tmp);
void	print_from_diff(t_lem lem, char **diff, int *start);
void	ini_moves(t_path slt, int size, int nb);
void	add_paths(t_path slt, int size, char **com);
void	move_one_step(char **path, int size);
char	**ini_diff(int size, char **new, char **old);
void	print_moves(t_lem lem, int j, int *start, int opt);
int		ft_strcount(char *str, char c);
void	ini_ants(t_lem lem, int *ants);
void	put_horizontal(char *str, int width, int x1, int y1);
void	put_vertical(char *str, int width, int x1, int y1);
void	put_up(char *str, int width, int x1, int y1);
void	put_down(char *str, int width, int x1, int y1);

#endif
