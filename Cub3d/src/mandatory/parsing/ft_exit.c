/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:57:45 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 19:35:56 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_ll(void)
{
	t_node	*node;
	t_node	*tmp;

	node = *ll_head();
	while (node)
	{
		tmp = node;
		free(node->line);
		node = node->next;
		free(tmp);
	}
}

void	free_map(void)
{
	t_cub	*cub;
	int		i;
	char	**map;

	cub = get_cub();
	map = cub->grid;
	i = 0;
	while (i < cub->count_map_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(int stage)
{
	t_cub	*cub;

	cub = get_cub();
	free(cub->east_texture);
	free(cub->west_texture);
	free(cub->south_texture);
	free(cub->north_texture);
	if (stage == 1)
		return ;
	free_ll();
	if (stage == 2)
		return ;
	free_map();
	if (stage == 3)
		return ;
}

void	ft_exit(char *msg, int status)
{
	free_all(status);
	printf("%s\n", msg);
	exit(status);
}

void	free_textures(void)
{
	t_cub	*cub;

	cub = get_cub();
	free(cub->east_texture);
	free(cub->west_texture);
	free(cub->south_texture);
	free(cub->north_texture);
}
