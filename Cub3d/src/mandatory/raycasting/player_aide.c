/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_aide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:58:01 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/10 00:03:36 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	init_player(t_player *player, t_cub *cub)
{
	player->x = (cub->player_x + 0.5f) * BLOCK;
	player->y = (cub->player_y + 0.5f) * BLOCK;
	if (cub->player_direction == 'N')
		player->angle = PI_M / 2;
	else if (cub->player_direction == 'S')
		player->angle = 3 * PI_M / 2;
	else if (cub->player_direction == 'E')
		player->angle = PI_M;
	else if (cub->player_direction == 'W')
		player->angle = 0;
	else
		player->angle = PI_M;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	else if (keycode == S)
		game->player.key_down = true;
	else if (keycode == A)
		game->player.key_left = true;
	else if (keycode == D)
		game->player.key_right = true;
	else if (keycode == LEFT)
		game->player.left_rotate = true;
	else if (keycode == RIGHT)
		game->player.right_rotate = true;
	else if (keycode == 65307)
		mlx_loop_end(game->mlx);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}
