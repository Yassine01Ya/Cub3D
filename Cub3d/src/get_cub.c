/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:00:12 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/10 19:31:18 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "cub3d.h"

int	verify_extention(char *filename, char *cub_extention)
{
	int	i;
	int	j;

	j = 3;
	i = ft_strlen(filename) - 1;
	while (i > -1 && j > -1)
	{
		if (filename[i] != cub_extention[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

t_cub	*get_cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	init_cub(void)
{
	t_cub	*cub;

	cub = get_cub();
	cub->player_x = -1;
	cub->player_y = -1;
	cub->grid = NULL;
	cub->colors_check[0] = 0;
	cub->colors_check[1] = 0;
}

void	init_game_for_main(void)
{
	int		i;
	t_cub	*cub;
	t_game	game;

	cub = get_cub();
	game = (t_game){0};
	set_cub(cub);
	create_map(cub);
	check_map(cub);
	init_game(&game, cub);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(game.mlx, game.wall_tex[i].handler);
	free_textures();
	mlx_destroy_image(game.mlx, game.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
