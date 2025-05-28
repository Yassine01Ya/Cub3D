/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:42:56 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/10 18:27:55 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_len + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

unsigned int	get_img_pixel_at(t_image *img, int x, int y)
{
	char	*tmp;

	if (x >= img->width)
		x = img->width - 1;
	if (y >= img->height)
		y = img->height - 1;
	tmp = &(img->data[x * (img->bpp / 8) + y * img->size_len]);
	return (*(unsigned int *)tmp);
}

void	initialize_map(t_game *game, t_cub *cub)
{
	init_player(&game->player, cub);
	game->map = cub->grid;
	game->map_height = cub->count_map_lines * BLOCK;
	game->map_lines = cub->count_map_lines;
	game->map_width = cub->count_map_cols * BLOCK;
	game->map_cols = cub->count_map_cols;
}

void	init_game(t_game *game, t_cub *cub)
{
	initialize_map(game, cub);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit("Error\nmlx_faild", 3);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	if (game->win == NULL)
	{
		mlx_destroy_display(game->win);
		ft_exit("Error\nmlx_faild", 3);
	}
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->img == NULL)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		ft_exit("Error\nmlx_faild", 3);
	}
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_len, &game->endian);
	init_textures(game, cub);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	draw_loop(t_game *game)
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
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
