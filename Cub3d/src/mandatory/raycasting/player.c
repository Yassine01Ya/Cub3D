/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:42:53 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/09 23:21:05 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

static void	handle_player_rotation(t_player *player)
{
	float	rotation_speed;

	rotation_speed = 0.05f;
	if (player->left_rotate)
		player->angle -= rotation_speed;
	if (player->right_rotate)
		player->angle += rotation_speed;
	player->angle = fmod(player->angle, 2 * PI_M);
	if (player->angle < 0)
		player->angle += 2 * PI_M;
}

static void	calculate_forward_movement(t_player *player, float *new_x,
		float *new_y)
{
	float	move_speed;

	move_speed = 3.0f;
	if (player->key_up)
	{
		*new_x += cos(player->angle) * move_speed;
		*new_y += sin(player->angle) * move_speed;
	}
	if (player->key_down)
	{
		*new_x -= cos(player->angle) * move_speed;
		*new_y -= sin(player->angle) * move_speed;
	}
}

static void	calculate_strafe_movement(t_player *player, float *new_x,
		float *new_y)
{
	float	move_speed;

	move_speed = 3.0f;
	if (player->key_right)
	{
		*new_x += cos(player->angle + PI_M / 2) * move_speed;
		*new_y += sin(player->angle + PI_M / 2) * move_speed;
	}
	if (player->key_left)
	{
		*new_x += cos(player->angle - PI_M / 2) * move_speed;
		*new_y += sin(player->angle - PI_M / 2) * move_speed;
	}
}

static void	update_ppos(t_player *player, float nx, float ny, t_game *game)
{
	float	buffer;

	buffer = 5.0f;
	if (!touch(nx + buffer, player->y, game) && !touch(nx - buffer,
			player->y, game))
	{
		player->x = nx;
	}
	if (!touch(player->x, ny + buffer, game) && !touch(player->x, ny
			- buffer, game))
	{
		player->y = ny;
	}
}

void	move_player(t_player *player, t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
	handle_player_rotation(player);
	calculate_forward_movement(player, &new_x, &new_y);
	calculate_strafe_movement(player, &new_x, &new_y);
	update_ppos(player, new_x, new_y, game);
}
