#ifndef PUSHSWAP_H
#define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define INTMIN -2147483648
# define INTMAX 2147483647

//peut etre aussi l'index
//s_stack		*prev;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;

//Main.c
void	printError(void);

//Check.c
bool	checkInput(char **av);
bool	checkArg(char **arg);
bool	ftIsDigit(char *arg);
bool	checkSign(char *arg);
bool	checkLimits(char *arg);

//Fill.c
bool	fillStackA(char **av, t_stack **stackA);

//List.c
t_stack	*create_node(char *arg);
void	pushback(char *arg, t_stack **head);

//ft_atoi.c
long	ft_atoi(const char *str);

//ft_split.c
char	**ft_split(char const *s, char c);

//test.c
void	testFillStack(t_stack *stackA);

#endif