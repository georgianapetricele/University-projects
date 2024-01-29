%a. Write a predicate to compute the intersection of two sets.
%
%
% inter(l1..ln,q1..qn) = l1 U inter(l2..ln,q1..qn), if cont(q1..qn,l1)=t
%                      = inter(l2..ln,q1..qn), otherwise
%           = [], if one is empty
%


cont([E|_],E):-!.
cont([_|T],E):-
    cont(T,E).

inter([],_,[]):-!.
inter(_,[],[]):-!.
inter([H1|T1],B,[H1|Int]):-
    cont(B,H1),
    inter(T1,B,Int),!.
inter([_|T1],B,Int):-
    inter(T1,B,Int).

% b. Write a predicate to create a list (m, ..., n) of all integer numbers from the interval [m, n].
%
%
%create(M,N) = MU create(M+1,N), if M<=n
%             = [M], if M=N

create(M,M,[M]).
create(M,N,[M|R]):-
    M2 is M+1,
    create(M2,N,R).
