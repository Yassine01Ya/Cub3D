/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:44 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/10 03:13:04 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

int	main(int c, char **v)
{
	if (c < 2)
		exit(0);
	init_cub();
	if (read_file_cub(v[1]))
		ft_exit("Error\nReading file", 3);
	else if (verify_extention(v[1], ".cub"))
	{
		init_game_for_main();
		free_ll();
		free_map();
		return (0);
	}
	else
		ft_exit("Error\nFile Extention", 3);
}
