/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:42:34 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 04:30:58 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file_cub(char *filename)
{
	char	*line;
	int		fd1;
	t_node	*node;

	fd1 = open(filename, O_RDONLY);
	if (fd1 == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		node = ll_new_node(line);
		ll_add_node(node);
	}
	close(fd1);
	return (0);
}
