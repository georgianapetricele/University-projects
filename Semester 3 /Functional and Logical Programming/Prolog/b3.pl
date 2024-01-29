%1.2

aux(K1,X,Y):-
    Y>1,!,
    K2 is K1-1,
    X is K2.
aux(_,X,Y):-
    Y>0.5,!,
    X is Y.
aux(_,X,Y):-
    X is Y-1.


f(1,1):-!.
f(K,X):-
    K1 is K-1,
    f(K1,Y),
    aux(K1,X,Y).

f1(1,1):-!.
f1(K,X):-
    K1 is K-1,
    f1(K1,Y),
    Y>1,!,
    K2 is K1-1,
    X is K2.
f1(K,X):-
    K1 is K-1,
    f1(K1,Y),
    Y>0.5,!,
    X is Y.
f1(K,X):-
    K1 is K-1,
    f1(K1,Y),
    X is Y-1.

p(1).
p(2).
q(1).
q(2).
r(1).
r(2).
s:- p(X),!,q(Y),r(Z),write(X),write(Y),write(Z),nl.

%aranjamente
%
%prod(l1..ln) = l1, if n=1
%             = l1 * prod(l2..ln)
%
prod([E],E).
prod([H|T],R):-
    prod(T,RP),
    R is H*RP.
%
%insert(e,l1..ln) = e U l1..ln
%                 = l1 U insert(e,l2..ln)
%
%(i,i,o)
insert(E,L,[E|L]).
insert(E,[H|T],[H|R]):-
    insert(E,T,R).

%arrangements
%
%arr(l1..ln,k) = l1, if k=1
%              = arr(l2..ln,k), if k>=1
%              = insert(l1,arr(l2..ln,k-1)), k>1
%arr(L:list,K:nr)
%
%(i,i,o)
arr([E|_],1,[E]).
arr([_|T],K,R):-
    arr(T,K,R).
arr([H|T],K,R1):-
    K>1,
    K1 is K-1,
    arr(T,K1,R),
    insert(H,R,R1).

onesol(L,K,V,R):-
    arr(L,K,R),
    prod(R,RP),
    RP <V.
allsol(L,K,V,R):-
    findall(RA,onesol(L,K,V,RA),R).



