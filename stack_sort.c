/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:18:22 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:09:05 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	if (is_sorted(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size >= 4 && size <= 20)
		sort_simple(stack_a, stack_b);
	else if (size > 5)
	{
		sort_large(stack_a, stack_b);
	}
}

int	is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_three(t_list **stack_a)
{
	int	smallest;

	if (!stack_a || !*stack_a || is_sorted(*stack_a) == 1)
		return ;
	smallest = find_smallest(*stack_a);
	if (smallest == 0)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (smallest == 1)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			ra(stack_a);
		else
			sa(stack_a);
	}
	else
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		rra(stack_a);
	}
}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	div;
	int	small;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		small = find_smallest(*stack_a);
		div = size / 2;
		if ((*stack_a)->index != small)
		{
			if (small <= div)
				ra(stack_a);
			else
				rra(stack_a);
		}
		else
		{
			pb(stack_a, stack_b);
			size--;
		}
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
