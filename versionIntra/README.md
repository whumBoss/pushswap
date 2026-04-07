*This project has been created as part of the 42 curriculum by wihumeau*.

## Description

Push_swap is a 42 project, that is designed to sort nombers is ascending order. The purpuse of this projet is to work with algorithm, the algo is the part of the programme that is going to sort. And it also helps to become more familiar with parsing, the parsing is the part of the program that checks all the arguments puts in entre and handles the assignation of theses same arguments.

## Instructions

There must be a list two numbers in entre. With or without double quotes. Sorted or not. Positive and negative.
Less parameters, the program doesn't displays anything.
Any other characters will not be taken as parameters and the progam stops. If there are + or - signs alone or more than one before the number the program also stops. Displaying error.
When the program sorts the arguments at each mouvement will be written in the terminal.
Mouvements are limited to the mouvments explaned in the subject.
In addition we should sort in a limited number of mouvements:
for 3 arguments the program have to sort in 3 mouvments or less
for 5 arguments it sorts in 12 mouvments or less
for 100 arguments it sorts in 700 mouvments or less
for 500 arguments it sorts in 5500 mouvments or less

## Test

make

./push_swap 3 1 5 4 8 34 -98 56 -6

The line to test with the checker:

ARG=($(python3 -c "import random; l=list(range(0, 5)); random.shuffle(l); print(*l)"))
./push_swap ${ARG[@]} | ./checker_linux ${ARG[@]}
./push_swap ${ARG[@]} | wc -l
echo ${ARG[@]}

## Ressources

I been looking for mouvement explanations on Youtube. And i have asked a lot of different peers about the project in general and their algorithm and parsing choices. It helped me choose one. 

* [youtube push_swap presantation](https://www.youtube.com/watch?v=wRvipSG4Mmk)


## Choice

I have chosen to implement an unconventionnal algorithm made basicli with chunks but evolutif ones. So in any case, no matter the number of numbers put as arguments the program with always sort in an resenable number of mouvments.