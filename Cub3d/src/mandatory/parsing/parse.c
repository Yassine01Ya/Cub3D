/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:44:07 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 19:06:50 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cub(t_cub *cub)
{
	t_node	*head;

	head = *ll_head();
	while (head)
	{
		if (ft_strncmp(head->line, "NO ", 3) == 0)
			set_config(&cub->north_texture, head);
		else if (ft_strncmp(head->line, "SO ", 3) == 0)
			set_config(&cub->south_texture, head);
		else if (ft_strncmp(head->line, "WE ", 3) == 0)
			set_config(&cub->west_texture, head);
		else if (ft_strncmp(head->line, "EA ", 3) == 0)
			set_config(&cub->east_texture, head);
		else if (ft_strncmp(head->line, "F ", 2) == 0)
			parse_color(head, cub, FLOOR);
		else if (ft_strncmp(head->line, "C ", 2) == 0)
			parse_color(head, cub, CEILING);
		else if (check_empty_line(head->line) && !check_config_color(cub))
			head->is_set = 1;
		else if (!check_config_color(cub))
			ft_exit("Error\nSet Floor or Ceiling color", 3);
		head = head->next;
	}
}
