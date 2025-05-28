/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:13:46 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/07 20:35:05 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

static void	draw_wall_block(t_wall_block *wall, t_center *c, t_game *game)
{
	int		wy;
	int		wx;
	int		draw_x;
	int		draw_y;

	wy = 0;
	while (wy < wall->wall_size)
	{
		wx = 0;
		while (wx < wall->wall_size)
		{
			draw_x = wall->wall_x + wx;
			draw_y = wall->wall_y + wy;
			if (is_in_circle(draw_x, draw_y, c))
				put_pixel(draw_x, draw_y, MINIMAP_WALL_COLOR, game);
			wx++;
		}
		wy++;
	}
}

static void	draw_map_cell(t_draw_cell *params, t_center *c, t_game *game)
{
	t_wall_block	wall;

	wall.wall_x = params->offset_x + (params->x * BLOCK * MINIMAP_SCALE);
	wall.wall_y = params->offset_y + (params->y * BLOCK * MINIMAP_SCALE);
	wall.wall_size = params->wall_size;
	draw_wall_block(&wall, c, game);
}

void	draw_minimap_walls(t_center *c, float offset_x, float offset_y,
		t_game *game)
{
	t_draw_cell	params;
	int			y;
	int			x;

	params.wall_size = BLOCK * MINIMAP_SCALE;
	y = 0;
	while (y < game->map_lines)
	{
		x = 0;
		while (x < game->map_cols)
		{
			if (game->map[y][x] == '1')
			{
				params.x = x;
				params.y = y;
				params.offset_x = offset_x;
				params.offset_y = offset_y;
				draw_map_cell(&params, c, game);
			}
			x++;
		}
		y++;
	}
}

static void	draw_player_direction(t_center *c, t_game *game)
{
	t_pminimap	draw;
	int			i;

	draw.dir_length = MINIMAP_PLAYER_SIZE * 4;
	draw.dir_x = c->center_x + cos(game->player.angle) * draw.dir_length;
	draw.dir_y = c->center_y + sin(game->player.angle) * draw.dir_length;
	draw.dx = draw.dir_x - c->center_x;
	draw.dy = draw.dir_y - c->center_y;
	draw.steps = fmax(fabs(draw.dx), fabs(draw.dy));
	draw.x_inc = draw.dx / draw.steps;
	draw.y_inc = draw.dy / draw.steps;
	draw.x = c->center_x;
	draw.y = c->center_y;
	i = 0;
	while (i < draw.steps)
	{
		if (is_in_circle(draw.x, draw.y, c))
			put_pixel(draw.x, draw.y, MINIMAP_PLAYER_COLOR, game);
		draw.x += draw.x_inc;
		draw.y += draw.y_inc;
		i++;
	}
}

void	draw_minimap_player(t_center *c, t_game *game)
{
	draw_filled_circle(c, MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_COLOR, game);
	draw_player_direction(c, game);
}
