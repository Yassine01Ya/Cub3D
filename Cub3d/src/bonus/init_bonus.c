/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:30:40 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/09 18:31:28 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

int	draw_loop_bonus(t_game *game)
{
	t_cub		*cub;
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	cub = get_cub();
	player = &game->player;
	move_player(player, game);
	fraction = PI_M / 3 / WIDTH;
	start_x = player->angle - PI_M / 6;
	put_color_background(game, 0, HEIGHT / 2, cub->ceiling_color);
	put_color_background(game, HEIGHT / 2, HEIGHT, cub->floor_color);
	i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
