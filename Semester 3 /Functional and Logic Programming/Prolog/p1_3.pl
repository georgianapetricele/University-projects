%a. Define a predicate to remove from a list all repetitive elements.

% remOc(E,l1,..ln) = empty, if n=0
%                 = rem(E,l2,..ln) if l1=E
%                 = l1 U rem(E,l2,..ln)
%

remOc(_,[],[]).
remOc(E,[H|T],Rez):-
    H =:= E,
    remOc(E,T,Rez).
remOc(E,[H|T],[H|Rez]):-
    H =\= E,
    remOc(E,T,Rez).


%rem_rep(l1..ln) = [], if n=0
%                = l1 U rem_rep(l2..ln), if occ(l1)=1
%
%                = rem_rep(l2..ln), if occ(l1) >1
%
occ([],_,0).
occ([H|T],E,N):- H=:=E,
    occ(T,E,Nr),
    N is Nr+1.
occ([H|T],E,Nr):- H=\=E,
    occ(T,E,Nr).


rem_rep([],[]).
rem_rep([H|T],[H|R]):-
    occ([H|T],H,Nr),
    Nr=:=1,
    rem_rep(T,R).
rem_rep([H|T],R):-
    occ([H|T],H,Nr),
    Nr=\=1,
    remOc(H,[H|T],Rr),
    rem_rep(Rr,R).


%b. Remove all occurrence of a maximum value from a list on integer numbers.

maxi(A,B,A):- A>=B.
maxi(A,B,B):- A<B.

%max_list(l1..ln) = l1, if n=1
%                 = maxi(l1,max_list(l2,..ln)), otherwise

max_list([A],A).
max_list([H|T],Res):-
    max_list(T,Rm),
    maxi(H,Rm,Res).

%main method where i call rem_rep
main(L,Rez):-
    max_list(L,Max),
    remOc(Max,L,Rez).


















