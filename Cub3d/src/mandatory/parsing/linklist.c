/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:42:07 by yafilali          #+#    #+#             */
/*   Updated: 2025/04/10 03:13:30 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_node	**ll_head(void)
{
	static t_node	*head = NULL;

	return (&head);
}

t_node	*ll_new_node(char *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->line = data;
	node->is_set = 0;
	node->next = NULL;
	return (node);
}

void	ll_add_node(t_node *node)
{
	t_node	**ll;
	t_node	*head;

	ll = ll_head();
	if (*ll == NULL)
	{
		*ll = node;
		return ;
	}
	head = *ll;
	while (head->next != NULL)
		head = head->next;
	head->next = node;
}

int	get_max_len(void)
{
	int		max;
	t_node	*head;

	max = 0;
	head = *ll_head();
	if (!head)
		return (-1);
	while (head)
	{
		if (head->is_set == 0)
			break ;
		head = head->next;
	}
	while (head != NULL)
	{
		if ((int)ft_strlen(head->line) > max)
			max = ft_strlen(head->line);
		head = head->next;
	}
	return (max);
}

int	count_map_lines(void)
{
	t_node	*head;
	int		count;

	count = 0;
	head = *ll_head();
	if (!head)
		return (-1);
	while (head)
	{
		if (check_empty_line(head->line))
			head->is_set = 1;
		if (head->is_set == 0)
			break ;
		head = head->next;
	}
	while (head != NULL)
	{
		count++;
		if (check_empty_line(head->line))
			ft_exit("Error\nNew Line in The Map", 3);
		head = head->next;
	}
	return (count);
}
