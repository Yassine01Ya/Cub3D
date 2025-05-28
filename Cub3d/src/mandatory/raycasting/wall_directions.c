/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:42:44 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/08 03:34:43 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	trace_ray(float sx, t_player *player, t_ray_data *ray, t_game *game)
{
	float	cos_angle;
	float	sin_angle;
	float	step_size;

	cos_angle = cos(sx);
	sin_angle = sin(sx);
	ray->ray_x = player->x;
	ray->ray_y = player->y;
	step_size = 0.1;
	ray->prev_x = 0;
	ray->prev_y = 0;
	while (!touch(ray->ray_x, ray->ray_y, game) && ray->ray_x >= 0
		&& ray->ray_y >= 0 && ray->ray_x < game->map_width
		&& ray->ray_y < game->map_height)
	{
		ray->prev_x = ray->ray_x;
		ray->prev_y = ray->ray_y;
		ray->ray_x += cos_angle * step_size;
		ray->ray_y += sin_angle * step_size;
	}
}

int	dwall_dir(float ray_x, float ray_y, float prev_x, float prev_y)
{
	int	map_x;
	int	map_y;
	int	prev_map_x;
	int	prev_map_y;

	map_x = (int)(ray_x / BLOCK);
	map_y = (int)(ray_y / BLOCK);
	prev_map_x = (int)(prev_x / BLOCK);
	prev_map_y = (int)(prev_y / BLOCK);
	if (map_x != prev_map_x)
	{
		if (ray_x > prev_x)
			return (WEST);
		else
			return (EAST);
	}
	else if (map_y != prev_map_y)
	{
		if (ray_y > prev_y)
			return (NORTH);
		else
			return (SOUTH);
	}
	return (NORTH);
}

void	calculate_wall_height(t_player *player, float ray_x, float ray_y,
		t_ray_data *ray)
{
	float	dist;
	float	height;

	dist = fixed_dist(player, ray_x, ray_y);
	height = (BLOCK / dist) * (WIDTH / 2);
	ray->start_y = (HEIGHT - height) / 2;
	ray->end_y = ray->start_y + height;
}
