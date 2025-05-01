/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_and_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:43:15 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:08:35 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	rank(t_list **stack_a)
{
	t_list	*current;
	t_list	*runner;
	int		rank;

	if (!stack_a || !*stack_a)
		return ;
	current = *stack_a;
	while (current)
	{
		rank = 0;
		runner = *stack_a;
		while (runner)
		{
			if (current->content > runner->content)
				rank++;
			runner = runner->next;
		}
		current->rank = rank;
		current = current->next;
	}
}
