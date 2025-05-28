/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:42:48 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/09 23:00:32 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	draw_textured_line(int i, t_ray_data *ray, t_game *game)
{
	t_image	*wall_tex;
	float	y_step;
	float	y_pixel;
	int		color;
	int		current_y;

	wall_tex = &game->wall_tex[ray->wall_dir];
	ray->x_pixel *= wall_tex->width;
	y_step = (wall_tex->height * 1.0f) / (ray->end_y - ray->start_y);
	y_pixel = 0;
	current_y = ray->start_y;
	while (current_y < ray->end_y)
	{
		color = get_img_pixel_at(wall_tex, ray->x_pixel, y_pixel);
		put_pixel(i, current_y, color, game);
		current_y++;
		y_pixel += y_step;
	}
}

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	t_ray_data	r;

	r.wall_dir = NORTH;
	trace_ray(start_x, player, &r, game);
	r.wall_dir = dwall_dir(r.ray_x, r.ray_y, r.prev_x, r.prev_y);
	calculate_wall_height(player, r.ray_x, r.ray_y, &r);
	if (r.wall_dir == NORTH || r.wall_dir == EAST)
		r.x_pixel = 1 - fmod(r.ray_x + r.ray_y, BLOCK) / BLOCK;
	else
		r.x_pixel = fmod(r.ray_x + r.ray_y, BLOCK) / BLOCK;
	draw_textured_line(i, &r, game);
}

void	put_color_background(t_game *game, int h_start, int h_max, int color)
{
	int	i;

	while (h_start < h_max)
	{
		i = 0;
		while (i < WIDTH)
		{
			put_pixel(i, h_start, color, game);
			i++;
		}
		h_start++;
	}
}
