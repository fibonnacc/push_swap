/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:50:24 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/03 09:44:35 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				rank;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
void				sa(t_list **stack_a);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ra(t_list **stack_a);
void				rra(t_list **stack_a);
int					is_number(char *str);
int					ft_atol(char *str, int *error);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_calloc(size_t num, size_t size);
void				ft_bzero(void *s, size_t len);
int					ft_duplicat(t_list *stack_a, int num);
int					check_and_convert(char *str, int *num);
void				ft_lstclear(t_list **lst);
void				free_string(char **arr);
void				error_exit(t_list **stack_a, t_list **stack_b);
int					process_number(char *number, t_list **stack_a);
int					process_numbers(char **numbers, t_list **stack_a);
int					process_arg(int ac, char **av, t_list **stack_a);
int					ft_lstsize(t_list *stack);
int					find_smallest(t_list *stack_a);
void				sort_three(t_list **stack_a);
void				sort_stack(t_list **stack_a, t_list **stack_b);
int					is_sorted(t_list *stack_a);
void				update_index(t_list *stack);
int					large_bit(t_list *stack_a);
void				rank(t_list **stack_a);
void				sort_large(t_list **stack_a, t_list **stack_b);
void				ft_my_fix(t_list **stack_a, t_list **stack_b, int i);
void				check_sign(char *str, int *sign, int *i);
void				sort_simple(t_list **stack_a, t_list **stack_b);

#endif
