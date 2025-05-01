/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smallest_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:15:56 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:07:40 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *stack_a)
{
	int	smallest;
	int	smallest_index;

	if (!stack_a)
		return (-1);
	smallest = stack_a->content;
	smallest_index = stack_a->index;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < smallest)
		{
			smallest = stack_a->content;
			smallest_index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (smallest_index);
}

void	update_index(t_list *stack)
{
	t_list	*current;
	int		i;

	i = 0;
	current = stack;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}
