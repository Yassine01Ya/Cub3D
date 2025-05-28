/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:42:53 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/07 01:43:38 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char a)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	if (a == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (n != '\0' && i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*rs;

	if (count && size > __INT_MAX__ / count)
		return (0);
	rs = malloc(count * size);
	if (!rs)
		return (NULL);
	ft_bzero(rs, count * size);
	return (rs);
}
