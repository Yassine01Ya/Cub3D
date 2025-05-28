/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:40:54 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 02:25:53 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		return (0);
	str = (char *)malloc(sizeof(char) * ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i])
	{
		str[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			break ;
		else
			i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	res = malloc(sizeof(char) * s_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	count_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	r;
	int			s;

	i = 0;
	r = 0;
	s = 1;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		r = (r * 10) + (str[i] - 48);
		if (r >= 9223372036854775807 && s == 1)
			return (-1);
		if (r >= 9223372036854775807 && s == -1)
			return (0);
		i++;
	}
	return (r * s);
}
