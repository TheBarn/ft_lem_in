/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:12:10 by barnout           #+#    #+#             */
/*   Updated: 2017/04/07 11:16:51 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct	s_room
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

#endif
