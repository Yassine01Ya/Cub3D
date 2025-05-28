/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:18:46 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 04:35:10 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_search(char *haystack, char needle)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (1);
		i++;
	}
	return (0);
}

void	set_p_pos(int x, int y)
{
	t_cub	*cub;

	cub = get_cub();
	if (cub->player_x != -1 || cub->player_y != -1)
		ft_exit("Error\nMultipe position player", 3);
	cub->player_x = x;
	cub->player_y = y;
	cub->player_direction = cub->grid[y][x];
}

char	*create_line(char *line, int len)
{
	char	*new_line;
	int		i;
	int		line_size;

	new_line = malloc(sizeof(char) * len + 1);
	line_size = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (i >= line_size)
			new_line[i] = '0';
		else if (line[i] != '\0' && (line[i] == ' ' || line[i] == '\n'
				|| line[i] == '\r'))
			new_line[i] = '0';
		else if (line[i] != '\0')
			new_line[i] = line[i];
		else
			new_line[i] = '0';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	create_map(t_cub *cub)
{
	int		lines;
	t_node	*node;
	int		i;

	lines = count_map_lines();
	node = *ll_head();
	i = 0;
	cub->count_map_cols = get_max_len();
	if (lines < 3)
		ft_exit("Error\nMap too small", 3);
	cub->count_map_lines = lines;
	cub->grid = malloc(sizeof(char *) * (lines + 1));
	while (node)
	{
		if (node->is_set != 1)
			break ;
		node = node->next;
	}
	while (node)
	{
		cub->grid[i] = create_line(node->line, cub->count_map_cols);
		node = node->next;
		i++;
	}
	cub->grid[i] = NULL;
}

void	check_map(t_cub *cub)
{
	char	**maps;
	int		i;
	int		j;

	i = 0;
	j = 0;
	maps = cub->grid;
	while (i < cub->count_map_lines)
	{
		while (maps[i][j])
		{
			if (!ft_search("01NSEW", maps[i][j]))
				ft_exit("Error\nInvalid character in map", 3);
			if (ft_search("NSEW", maps[i][j]))
				set_p_pos(j, i);
			j++;
		}
		j = 0;
		i++;
	}
	if (cub->player_x == -1 || cub->player_y == -1)
		ft_exit("Error\nNo player position", 3);
	if (!is_map_closed(cub))
		ft_exit("Error\nMap validation failed.", 3);
}
