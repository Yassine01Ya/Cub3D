/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:39:48 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/08 02:10:07 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	flood_fill(int **visited, t_cub *cub, int player_x, int player_y)
{
	int	rows;
	int	cols;

	rows = cub->count_map_lines;
	cols = cub->count_map_cols;
	if (player_x < 0 || player_x >= cols || player_y < 0 || player_y >= rows
		|| cub->grid[player_y][player_x] == '1'
		|| visited[player_y][player_x])
		return (2);
	if (player_x == 0 || player_x == cols - 1 || player_y == 0
		|| player_y == rows - 1)
		return (0);
	visited[player_y][player_x] = 1;
	return (flood_fill(visited, cub, player_x + 1, player_y)
		&& flood_fill(visited, cub, player_x - 1, player_y)
		&& flood_fill(visited, cub, player_x, player_y + 1)
		&& flood_fill(visited, cub, player_x, player_y - 1));
}

static int	**create_visited(int rows, int cols)
{
	int	**visited;
	int	j;
	int	i;

	i = 0;
	visited = (int **)malloc(rows * sizeof(int *));
	if (!visited)
		return (NULL);
	while (i < rows)
	{
		visited[i] = (int *)malloc(cols * sizeof(int));
		if (!visited[i])
		{
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		j = 0;
		while (j < cols)
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}

static void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	is_map_closed(t_cub *cub)
{
	int	result;
	int	**visited;
	int	x;
	int	y;

	x = cub->player_x;
	y = cub->player_y;
	if (x == 0 || x == cub->count_map_lines || y == 0
		|| y == cub->count_map_cols)
		return (0);
	visited = create_visited(cub->count_map_lines, cub->count_map_cols);
	if (!visited)
		return (0);
	result = flood_fill(visited, cub, cub->player_x, cub->player_y);
	free_visited(visited, cub->count_map_lines);
	return (result);
}
