#ifndef PUSHSWAP_H
#define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INTMIN 
# define INTMAX

typedef struct s_stack
{
	//peut etre aussi l'index
	int			value;
	s_stack		*next;
} t_stack;

//Main.c
void	printError(void);

//Check.c
bool	checkInput(char **av);
bool	checkArg(char **arg);
bool	ftIsDigit(char **arg);
bool	checkSign(char **arg);
bool	checkLimits(char **arg);

//Fill.c
bool	fillStackA(int ac, t_stack *stackA);

#endif