/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:44 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/09 00:03:13 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	print_cub(t_cub *cub)
{
	printf("north: %s\n", cub->north_texture);
	printf("east: %s\n", cub->east_texture);
	printf("west: %s\n", cub->west_texture);
	printf("south: %s\n", cub->south_texture);
	printf("F = %d,%d,%d \n", cub->floor[0], cub->floor[1], cub->floor[2]);
	printf("C = %d,%d,%d \n", cub->ceiling[0], cub->ceiling[1],
		cub->ceiling[2]);
}

void	print_grid(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->count_map_lines)
	{
		printf("%s\n", cub->grid[i]);
		i++;
	}
}
