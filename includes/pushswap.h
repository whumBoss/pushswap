/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:39:44 by wihumeau          #+#    #+#             */
/*   Updated: 2026/04/05 22:20:08 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define INTMIN -2147483648
# define INTMAX 2147483647

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}t_stack;

//Main.c
void	print_error(char *str);

//Check.c
int		check_input(char **av);
int		check_arg(char **arg);
int		ft_is_digit(char *arg);
int		check_sign(char *arg);
int		check_limits(char *arg);

//Fill.c
void	assign_index(t_stack **satck_a);
int		verif_doublon(t_stack *satck_a);
int		filling_stack(char **av, t_stack **satck_a);
int		fillsatck_a(char **av, t_stack **satck_a);

//List.c
int		size_list(t_stack *satck_a);
t_stack	*create_node(char *arg);
int		pushback(char *arg, t_stack **head);

//ft_atoi.c
long	ft_atoi(const char *str);

//ft_split.c
char	**ft_split(char const *s, char c);

//Free.c
void	free_stack(t_stack **satck_a);
void	free_tab(char **tab);

//Mouv_sp
void	mv_swap(t_stack **stack, char *mouv_name);
void	mv_sswap(t_stack **satck_a, t_stack **satck_b);
void	mv_push(t_stack **stack_origin, t_stack **stack_dest, char *mouv_name);

//Mouv_rrr.c
void	mv_rotate(t_stack **stack, char *mouv_name);
void	mv_rr(t_stack **satck_a, t_stack **satck_b);
void	mv_reverse_rotate(t_stack **stack, char *mouv_name);
void	mv_rrr(t_stack **satck_a, t_stack **satck_b);

//Small_algo.c
void	which_algo(t_stack **satck_a, t_stack **satck_b);
int		count_nodes(t_stack *stack);
void	algo_two_nodes(t_stack **satck_a);
void	algo_three_nodes(t_stack **satck_a);
void	algo_four_five_nodes(t_stack **satck_a, t_stack **satck_b);

//Big_algo.c
int		find_node_position(t_stack *stack, int index);
void	find_biggest_node(t_stack **satck_b);
int		chunk_size(int stack_size);
void	algo_over_five(t_stack **satck_a, t_stack **satck_b, int list_size);

//Test.c
void	print_stack(t_stack *satck_a);

#endif