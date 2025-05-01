/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:16:31 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:06:32 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*top_node;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	top_node = *stack_a;
	*stack_a = (*stack_a)->next;
	top_node->next = NULL;
	ft_lstadd_back(stack_a, top_node);
	update_index(*stack_a);
	write(1, "ra\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;

	if (!stack_a || !*stack_a)
		return ;
	new = *stack_a;
	*stack_a = (*stack_a)->next;
	new->next = NULL;
	ft_lstadd_front(stack_b, new);
	update_index(*stack_b);
	update_index(*stack_a);
	write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*new;

	if (!stack_b || !*stack_b)
		return ;
	new = *stack_b;
	*stack_b = (*stack_b)->next;
	new->next = NULL;
	ft_lstadd_front(stack_a, new);
	update_index(*stack_a);
	update_index(*stack_b);
	write(1, "pa\n", 3);
}
