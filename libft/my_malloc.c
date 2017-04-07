/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:10:56 by barnout           #+#    #+#             */
/*   Updated: 2017/04/05 11:09:25 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void		*my_malloc(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst == NULL)
	{
		write(2, "Memory Allocation Error\n", 24);
		exit(0);
	}
	ft_memset(dst, 0, size);
	return (dst);
}
