/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:36:12 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 19:34:59 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_config(char **line_path, t_node *node)
{
	char	*file;
	int		fd;
	int		i;

	i = 0;
	file = node->line + 3;
	while (file[i])
	{
		if (file[i] == '\n' || file[i] == '\r')
		{
			file[i] = '\0';
			break ;
		}
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error\nInvalid texture path", 3);
	if (*line_path)
		free(*line_path);
	*line_path = ft_strdup(file);
	if (file == NULL)
		return ;
	node->is_set = 1;
}

int	check_config_color(t_cub *cub)
{
	if (!cub->colors_check[0] || !cub->colors_check[1])
		return (0);
	return (1);
}

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}
