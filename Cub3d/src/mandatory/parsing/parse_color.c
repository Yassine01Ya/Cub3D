/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:56:36 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 18:33:15 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_color(char *color)
{
	int	i;
	int	n;

	i = 0;
	while (color[i] != '\0' && color[i] != '\n' && color[i] != '\r')
	{
		if (color[i] < '0' || color[i] > '9' || i > 3)
			return (0);
		i++;
	}
	n = ft_atoi(color);
	if (n > 255)
		return (0);
	return (1);
}

char	**check_color_parse(t_cub *cub, t_node *node, t_color flag)
{
	char	**color;

	if (flag == FLOOR && cub->colors_check[0] == 1)
		ft_exit("Error: Floor color is already set", 3);
	else if (flag == CEILING && cub->colors_check[1] == 1)
		ft_exit("Error\nCeiling color is already set", 3);
	color = ft_split(node->line + 2, ',');
	if (!color || count_tab(color) != 3)
	{
		free_double(color);
		ft_exit("Error\nInvalid color format", 3);
	}
	if (!valid_color(color[0]) || !valid_color(color[1])
		|| !valid_color(color[2]))
	{
		free_double(color);
		ft_exit("Error\nInvalid color value", 3);
	}
	if (flag == FLOOR)
		cub->colors_check[0] = 1;
	else
		cub->colors_check[1] = 1;
	node->is_set = 1;
	return (color);
}

int	ft_pixel(int *rgb)
{
	return (0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	parse_color(t_node *node, t_cub *cub, t_color flag)
{
	int		*color;
	char	**components;
	int		i;

	components = check_color_parse(cub, node, flag);
	if (flag == FLOOR)
		color = cub->floor;
	else
		color = cub->ceiling;
	i = 0;
	if (components)
	{
		color[0] = ft_atoi(components[0]);
		color[1] = ft_atoi(components[1]);
		color[2] = ft_atoi(components[2]);
		while (components[i])
			free(components[i++]);
		free(components);
	}
	if (flag == FLOOR)
		cub->floor_color = ft_pixel(color);
	else
		cub->ceiling_color = ft_pixel(color);
}
