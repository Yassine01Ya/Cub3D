/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:13:58 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/07 20:33:06 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	draw_filled_circle(t_center *c, int radius, int color, t_game *game)
{
	int	y;
	int	x;
	int	draw_x;
	int	draw_y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				draw_x = c->center_x + x;
				draw_y = c->center_y + y;
				if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0
					&& draw_y < HEIGHT)
				{
					put_pixel(draw_x, draw_y, color, game);
				}
			}
			x++;
		}
		y++;
	}
}

void	draw_minimap_background(t_center *c, t_game *game)
{
	draw_filled_circle(c, PLAYER_RADIUS, MINIMAP_BG_COLOR, game);
}

static void	draw_minimap_border(t_center *c, t_game *game)
{
	int		angle;
	float	rad;
	int		x;
	int		y;

	angle = 0;
	while (angle < 360)
	{
		rad = angle * (PI_M / 180);
		x = c->center_x + cos(rad) * PLAYER_RADIUS;
		y = c->center_y + sin(rad) * PLAYER_RADIUS;
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			put_pixel(x, y, MINIMAP_BORDER_COLOR, game);
		}
		angle++;
	}
}

void	draw_minimap(t_game *game)
{
	t_center	c;
	float		offset_x;
	float		offset_y;

	c.center_x = WIDTH - PLAYER_RADIUS - MINIMAP_MARGIN;
	c.center_y = PLAYER_RADIUS + MINIMAP_MARGIN;
	draw_minimap_background(&c, game);
	offset_x = c.center_x - (game->player.x * MINIMAP_SCALE);
	offset_y = c.center_y - (game->player.y * MINIMAP_SCALE);
	draw_minimap_walls(&c, offset_x, offset_y, game);
	draw_minimap_player(&c, game);
	draw_minimap_border(&c, game);
}
