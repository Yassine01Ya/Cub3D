/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:13:11 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/09 18:32:08 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

bool	is_in_circle(int x, int y, t_center *c)
{
	int	dx;
	int	dy;

	dx = x - c->center_x;
	dy = y - c->center_y;
	return (dx * dx + dy * dy <= PLAYER_RADIUS * PLAYER_RADIUS);
}
