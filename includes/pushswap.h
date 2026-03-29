#ifndef PUSHSWAP_H
#define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define INTMIN -2147483648
# define INTMAX 2147483647

//peut etre aussi l'index
//s_stack		*prev;

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
} t_stack;

//Main.c
void	printError(char *str);

//Check.c
int	checkInput(char **av);
int	checkArg(char **arg);
int	ftIsDigit(char *arg);
int	checkSign(char *arg);
int	checkLimits(char *arg);

//Fill.c
int	assign_index(t_stack **stackA);
int	verif_doublon(t_stack *stackA);
int	fillStackA(char **av, t_stack **stackA);

//List.c
int	size_list(t_stack *stackA);
t_stack	*create_node(char *arg);
int	pushback(char *arg, t_stack **head);

//ft_atoi.c
long	ft_atoi(const char *str);

//ft_split.c
char	**ft_split(char const *s, char c);

//Free.c
void	free_stack(t_stack **stackA);
void	free_tab(char **tab);

//Test.c
void	testFillStack(t_stack *stackA);

#endif