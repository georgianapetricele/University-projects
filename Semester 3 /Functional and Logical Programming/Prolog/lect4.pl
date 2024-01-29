

% g(L:list, E: element, LRez: list)
% (i, i, o) – non-deterministic
%
g([H|_], E, [E,H]).
g([_|T], E, P) :-
    g(T, E, P).


% f(L:list, LRez: list)
% (i, o) – non-deterministic
%
f([H|T],P) :-
    g(T, H, P).
f([_|T], P) :-
    f(T, P).
