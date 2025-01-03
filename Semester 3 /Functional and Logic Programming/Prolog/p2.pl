%2.
% a. Sort a list with keeping double values in resulted list. E.g.: [4 2
% 6 2 3 4] --> [2 2 3 4 4 6]


bubblesort([],[]).
bubblesort(In, [H|Out]):-
  pulldown(In, [H|T]),
  bubblesort(T, Out),

pulldown([],[]).
pulldown([A], [A]).
pulldown([H|T], [H,X|Y]):-
  pulldown(T,[X|Y]),
  H =< X.

pulldown([H|T], [X,H|Y]):-
  pulldown(T,[X|Y]),
  H > X.
