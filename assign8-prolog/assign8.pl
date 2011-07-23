/********************************************************************/
/* File   : assign8.pl                                              */
/* Author : Keith Novelist Fancher                                  */
/* Class  : CS3490                                                  */
/* Date   : 04/21/04                                                */
/* Purpose: Prolog...                                               */
/********************************************************************/


/* 
Function   : mylast
Description: Takes a list and an element and returns Yes if the element is
             the last element of the list.
Examples   : 
             mylast([], X).       --> Prolog responds with No. 
             mylast([a], X).      --> X gets set to a.
             mylast([a, b, c], X) --> X gets set to c.
             mylast([a, b, c], c) --> Prolog responds with Yes.
             mylast([a], a).      --> Prolog responds with Yes.
             mylast([a], []).     --> Prolog responds with No.
*/
mylast([X], X).
mylast([_|Y], Z) :- mylast(Y, Z).


/*
Function   : allbutnth
Description: Takes a list, a number 'n', and another list.  Returns Yes if the
             second list is equal to the first list without element number 'n'.  
Examples   :
             allbutnth([a, b, c], 0, [b, c]).  --> Prolog responds with Yes.
             allbutnth([a, b, c], 0, X).       --> X gets set to [b, c]
             allbutnth([a, b, c], 1, X).       --> X gets set to [a, c]
             allbutnth([a, b, c], 2, X).       --> X gets set to [a, b]
             allbutnth([a, b, c], 3, X).       --> Prolog responds with No.
             allbutnth([a, b, c], -1, X).      --> Prolog responds with No.
             allbutnth([a, b, c], a, X).       --> Prolog responds with No.
*/
allbutnth([_|Y], 0, Y).
allbutnth([X|Y], N, [P|F]) :- number(N), N>0, R is N-1, allbutnth(Y, R, Z), append([X], Z, [P|F]).


/*
Function   : insert
Description: Takes a number and two sorted lists and returns Yes if the third
             list is equal to the second list with the number inserted into it.
Examples   :
             insert(3, [2, 3, 4], [2, 3, 3, 4]). --> Prolog responds with Yes.
             insert(3, [4, 5, 6], [3, 4, 5, 6]). --> Prolog responds with Yes.
             insert(3, [4, 5, 6], X).            --> X gets set to [3, 4, 5, 6].
             insert(7, [4, 5, 6], X).            --> X gets set to [4, 5, 6, 7].
             insert(3, [], X).                   --> X gets set to [3].
*/
insert(N, [], [N]).
insert(N, [X|Y], [N, X|Y]) :- N<X.
insert(N, [X], [X, N]) :- N>X.
insert(N, [X,Y|Z], [X, N, Y|Z]) :- N>X, N=<Y.
insert(N, [X|Y], [W|Z]) :- insert(N, Y, R), append([X], R, [W|Z]).


/*
Function   : deletefirst
Description: Takes an element and two lists and returns Yes if the second list
             is equal to the first list with the first occurance of the element
             deleted.
Examples   :
             deletefirst(a, [a, b, a], X).     --> X gets set to [b, a]
             deletefirst(a, [b, a, c], X).     --> X gets set to [b, c]
             deletefirst(a, [b, c], X).        --> X gets set to [b, c]
             deletefirst(a, [a, b, a], [b, a]) --> Prolog responds with Yes.
             deletefirst(a, [], [])            --> Prolog responds with Yes.
             deletefirst(a, [], X).            --> X gets set to [].
*/
deletefirst(X, [X|Y], Y).
deletefirst(_, [Y], [Y]).
deletefirst(_, [], []).
deletefirst(X, [Y|Z], [R|Q]) :- deletefirst(X, Z, W), append([Y], W, [R|Q]).


/*
Function   : my_reverse
Description: Takes two lists and returns Yes if the second list is the reverse
               of the first list.
Examples   :
             reverse([], []).                --> prolog returns Yes
             reverse([], X).                 --> X gets set to []
             reverse([a, b, c], X).          --> X gets set to [c, b, a]
             reverse([a, b, c], [c, b, a]).  --> prolog returns Yes
*/
my_reverse([], []).
my_reverse([X,Y], [Y,X]).
my_reverse([X|Y], R):- my_reverse(Y, W), append(W, [X], R).

