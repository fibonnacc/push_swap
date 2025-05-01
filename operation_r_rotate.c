/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:20:20 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:06:46 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
	{
		return ;
	}
	last = *stack_a;
	while (last->next->next != NULL)
	{
		last = last->next;
	}
	second_last = last;
	last = last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	update_index(*stack_a);
	write(1, "rra\n", 4);
}
