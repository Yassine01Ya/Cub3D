/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:40:10 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/07 01:40:27 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_wordlen(s, c);
		s += i;
		if (i)
			w++;
	}
	return (w);
}

static char	*ft_wordcpy(char const *src, int i)
{
	char	*dest;

	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	dest[i] = '\0';
	while (i--)
		dest[i] = src[i];
	return (dest);
}

static char	**ft_free(char **str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		size;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	size = ft_wordcount(s, c);
	p = malloc((size + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		n = ft_wordlen(s, c);
		if (*s)
			p[i] = ft_wordcpy(s, n);
		if (!p[i])
			return (ft_free(p, i));
		s += n;
	}
	p[size] = 0;
	return (p);
}
