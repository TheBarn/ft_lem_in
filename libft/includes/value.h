/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:42:46 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 19:08:32 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
# define VALUE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft.h"

typedef	struct				s_value
{
	char					flags[5];
	int						width;
	int						precision;
	char					modifier;
	char					conversion;
	union
	{
		char				c;
		unsigned char		uc;
		short				shrt;
		unsigned			ushrt;
		int					nb;
		unsigned int		u;
		long				lg;
		unsigned long		ul;
		long long			llg;
		unsigned long long	ull;
		size_t				z;
		intmax_t			j;
		uintmax_t			uj;
		char				*str;
		unsigned long		ptr;
		wchar_t				*wstr;
	}						val;
}							t_value;

#endif
