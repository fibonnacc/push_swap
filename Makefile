NAME = push_swap

SRCS =	handle_errors.c	operation_r_rotate.c	radix_sort_algorithm.c	libft_part1.c	parse_input.c	size_and_rank.c \
	libft_part2.c	split_string.c	libft_part3.c	push_smallest_to_b.c  stack_sort.c \
	operation_for_swap.c	operation_push_rotate.c	push_swap_sources.c

OBJECT = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME) 

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
