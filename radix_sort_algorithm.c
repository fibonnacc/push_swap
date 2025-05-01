/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:17:22 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:08:23 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	large_bit(t_list *stack_a)
{
	int	max_value;
	int	max_bit;

	if (!stack_a)
		return (0);
	max_value = stack_a->rank;
	while (stack_a)
	{
		if (stack_a->rank > max_value)
			max_value = stack_a->rank;
		stack_a = stack_a->next;
	}
	max_bit = 0;
	while ((max_value >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	ft_my_fix(t_list **stack_a, t_list **stack_b, int i)
{
	int	list_size;
	int	j;

	list_size = ft_lstsize(*stack_a);
	j = 0;
	while (j++ < list_size)
	{
		if ((((*stack_a)->rank >> i) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;

	if (!*stack_a || !stack_a || !stack_b)
		return ;
	size = large_bit(*stack_a);
	i = 0;
	while (i < size)
	{
		ft_my_fix(stack_a, stack_b, i);
		i++;
	}
}
