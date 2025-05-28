/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:29:42 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/10 18:30:36 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

void	load_texture(t_game *game, t_image *texture, char *path)
{
	int	i;

	texture->handler = mlx_xpm_file_to_image(game->mlx, path,
			&texture->width, &texture->height);
	if (texture->handler == NULL)
	{
		mlx_destroy_image(game->mlx, game->img);
		i = 0;
		while (i < 4)
		{
			if (game->wall_tex[i].handler)
				mlx_destroy_image(game->mlx, game->wall_tex[i].handler);
			i++;
		}
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_exit("Error\nINVALID TEX", 3);
	}
	texture->data = mlx_get_data_addr(texture->handler, &texture->bpp,
			&texture->size_len, &texture->endian);
}

void	init_textures(t_game *game, t_cub *cub)
{
	char	*textures[4];
	int		directions[4];
	int		i;

	textures[0] = cub->north_texture;
	textures[1] = cub->south_texture;
	textures[2] = cub->east_texture;
	textures[3] = cub->west_texture;
	directions[0] = NORTH;
	directions[1] = SOUTH;
	directions[2] = EAST;
	directions[3] = WEST;
	i = 0;
	while (i < 4)
	{
		load_texture(game, &game->wall_tex[directions[i]], textures[i]);
		i++;
	}
}
