/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:38:47 by barnout           #+#    #+#             */
/*   Updated: 2016/11/27 18:26:26 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*rev_order(const char *str)
{
	long		i;
	long		len;
	char		*dst;

	len = ft_strlen(str);
	i = len - 1;
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (i >= 0)
	{
		dst[len - 1 - i] = str[i];
		i--;
	}
	dst[len] = '\0';
	return (dst);
}

char			*ft_strrchr(const char *s, int c)
{
	size_t		i;
	size_t		len;
	char		*rev;
	char		*str;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	c = (unsigned char)c;
	rev = (char *)malloc(len + 1);
	if (rev == NULL)
		return (NULL);
	if (c == '\0')
		return (&str[len]);
	rev = rev_order(str);
	while (rev[i] != '\0' && rev[i] != c)
		i++;
	if (rev[i] == '\0' && c != 0)
		return (NULL);
	return (&str[len - (i + 1)]);
}
