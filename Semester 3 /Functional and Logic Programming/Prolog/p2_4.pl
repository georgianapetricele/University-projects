%a. Write a predicate to determine the sum of two numbers written in list representation.
%

% Model matematic:
% my_append(l1...ln, e) =
% 	[e], n = 0
% 	l1 + my_append(l2...ln), otherwise

% my_append(L:list, E:number, R:list)
% flow model: my_append(i, i, o)

my_append([], E, [E]).
my_append([H|T], E, [H|R]) :-
    my_append(T, E, R).

% Model matematic:
% my_length(l1...ln) =
% 	0, n = 0
% 	1 + my_length(l2...ln), otherwise

% my_length(L:list, R:number)
% flow model: my_length(i, o)

my_length([], 0).
my_length([_|T], R) :-
    my_length(T, RC),
    R is RC + 1.

% Model matematic:
% inv_list(l1...ln) =
% 	[], n = 0
% 	my_append(inv_list(l2...ln), l1), otherwise

% inv_list(L:list, R:list)
% flow model: inv_list(i, o)

inv_list([], []).
inv_list([H|T], R) :-
    inv_list(T, RI),
    my_append(RI, H, R).

% Model matematic:
% sum_lists(a1...an, b1...bm) =
% 	a1...an, m = 0
% 	b1...bm, n = 0
% 	inv_list(suma(inv_list(a1...an), inv_list(b1...bm), 0)), n <= m
% 	inv_list(suma(inv_list(b1...bm), inv_list(a1...an), 0)), otherwise

% sum_lists(A:list, B:list, R:list)
% flow model: sum_lists(i, i, o)
sum_lists(A, [], A).
sum_lists([], B, B).
sum_lists(A, B, R) :-
    my_length(A, LA),
    my_length(B, LB),
    LA =< LB, !,
    inv_list(A, RA),
    inv_list(B, RB),
    suma(RA, RB, 0, RS),
    inv_list(RS, R).
sum_lists(A, B, R) :-
    inv_list(A, RA),
    inv_list(B, RB),
    suma(RB, RA, 0, RS),
    inv_list(RS, R).

% Model matematic:
% suma(a1...an, b1...bm, c) =
% 	[], n = 0 and m = 0 and c = 0
% 	[1], n = 0 and m = 0 and c = 1
% 	(b1 + c) + suma([], b2...bm, 0), n = 0 and b1 + c < 10
% 	((b1 + c) % 10) + suma([], b2...bm, 1), n = 0 and b1 + c > 10
% 	(a1 + b1 + c) + suma(a2...an, b2...bm, 0), a1 + b1 + c < 10
% 	((a1 + b1 + c) % 10) + suma(a2...an, b2...bm, 1), a1 + b1 + c > 10

suma([], [], 0, []).
suma([], [], 1, [1]).
suma([], [HB|TB], C, [HBC|R]) :-
    HBC is (HB + C) mod 10, 
    HBC - HB - C =:= 0,
    suma([], TB, 0, R).
suma([], [HB|TB], C, [HBC|R]) :-
    HBC is (HB + C) mod 10, 
    HBC - HB - C =\= 0,
    suma([], TB, 1, R).
suma([HA|TA], [HB|TB], C, [HR|R]) :-
    HR is (HA + HB + C) mod 10,
    HR - HA - HB - C =:= 0,
    suma(TA, TB, 0, R).
suma([HA|TA], [HB|TB], C, [HR|R]) :-
    HR is (HA + HB + C) mod 10,
    HR - HA - HB - C =\= 0,
    suma(TA, TB, 1, R).

% b

% Model matematic:
% heterList(l1...ln) = 
% 	[], n = 0
% 	sum_lists(l1, heterList(l2...ln)), is_list(l1) = True
% 	heterList(l2...ln), otherwise

% heterList(L:list, R:list)
% flow model: heterList(i, o)

heterList([], []).
heterList([H|T], R) :- is_list(H), !,
    heterList(T, RH),
    sum_lists(H, RH, R).
heterList([_|T], R) :-
    heterList(T, R).