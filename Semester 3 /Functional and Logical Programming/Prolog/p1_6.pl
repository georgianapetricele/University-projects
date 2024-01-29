%a. Write a predicate to test if a list is a set.
%
%is_set(l1..ln) = true, if n=0
%               = false, if nrOc(l1)>1
%               = is_set(l2..ln), otherwise
%

nrOc([],_,0).
nrOc([H|T],E,Nr1):- H=:=E,
    nrOc(T,E,Nr),
    Nr1 is Nr+1.
nrOc([H|T],E,Nr):- H=\=E,
    nrOc(T,E,Nr).

is_set([]).
is_set([H|T]):-
    nrOc([H|T],H,Nr),
    Nr =:= 1,
    is_set(T).
is_set([H|T]) :-
    nrOc([H|T], H, Nr),
    Nr > 1,
    false.

% b. Write a predicate to remove the first three occurrences of an el
%
%
%rem3(l1..ln,E,K) = [], if n=0
%               = l1..ln, if k=0
%               = rem3(l2..ln,E,K+1), if l1=E and K>0
%               = l1 U rem3(l2..ln,E,K), otherwise
%

rem3([],_,_,[]).
rem3(L,_,0,L):-!.
rem3([H|T],H,K,Res):-
    K1 is K-1,
    rem3(T,H,K1,Res).
rem3([H|T],E,K,[H|Res]):- H=\=E,
    rem3(T,E,K,Res).

remove([],_,[]).
remove(L,E,R):-
    rem3(L,E,3,R).







