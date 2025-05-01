/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:25 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:08:13 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_number(char *number, t_list **stack_a)
{
	int		num;
	t_list	*new;

	if (!number)
		return (0);
	if ((!check_and_convert(number, &num)) || (!ft_duplicat(*stack_a, num)))
		return (0);
	new = ft_lstnew(num);
	if (!new)
		return (0);
	ft_lstadd_back(stack_a, new);
	return (1);
}

int	process_numbers(char **numbers, t_list **stack_a)
{
	int	i;

	i = 0;
	if (!numbers || !*numbers)
		return (0);
	while (numbers[i])
	{
		if (!process_number(numbers[i], stack_a))
			return (0);
		i++;
	}
	return (1);
}

int	process_arg(int ac, char **av, t_list **stack_a)
{
	int		j;
	char	**numbers;

	j = 1;
	while (ac > j)
	{
		numbers = ft_split(av[j], ' ');
		if (!numbers || !numbers[0] || !process_numbers(numbers, stack_a))
			return (free_string(numbers), 0);
		free_string(numbers);
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
	{
		exit(0);
	}
	else if (!process_arg(ac, av, &stack_a))
	{
		error_exit(&stack_a, &stack_b);
	}
	rank(&stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
