/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:06:33 by barnout           #+#    #+#             */
/*   Updated: 2016/11/27 18:24:08 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t		i;
	size_t		toto;
	size_t		count;
	char		c2;

	i = 0;
	count = 0;
	toto = 0;
	c2 = c;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			toto++;
			i++;
		}
		if (toto != 0)
			count++;
		toto = 0;
	}
	return (count);
}

static int		word_len(const char *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**dest;
	int			count;
	size_t		w;

	w = 0;
	count = count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (dest == NULL)
		return (NULL);
	while (count--)
	{
		while (*s == c && *s != '\0')
			s++;
		dest[w] = ft_strsub(s, 0, word_len(s, c));
		if (dest[w] == NULL)
			return (NULL);
		s = s + word_len(s, c);
		w++;
	}
	dest[w] = NULL;
	return (dest);
}
