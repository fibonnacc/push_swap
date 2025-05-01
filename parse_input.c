/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:59:12 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/01 11:07:19 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicat(t_list *stack_a, int num)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_and_convert(char *str, int *num)
{
	int	temp;
	int	error;

	if (!str)
		return (0);
	error = 0;
	if (!is_number(str))
		return (0);
	temp = ft_atol(str, &error);
	if (temp && error == 1)
		return (0);
	*num = temp;
	return (1);
}
