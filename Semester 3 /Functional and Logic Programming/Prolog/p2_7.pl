%7. a. Determine the position of the maximal element of a linear list
%
%
%max_list(l1..ln) = [l1], if n=1
%               = maxi(l1,max_list(l2..ln))
%

maxi(A,B,A):- A>B.
maxi(A,B,B):- A=<B.

max_list([E],E).
max_list([H|T],Res):-
    max_list(T,Rm),
    maxi(H,Rm,Res).

%max_pos(l1..ln,max,Ind) = [], if n=0
%                        = Ind + max_pos(l2..ln,max,Ind+1), if max=l1
%                        = max_pos(l2..ln,max,Ind+1), otherwise
%

max_pos([],_,_,[]).
max_pos([H|T],M,Ind,[Ind|Res]):- H=:=M,
    Ind2 is Ind+1,
    max_pos(T,M,Ind2,Res).
max_pos([H|T],M,Ind,Res):- H=\=M,
    Ind2 is Ind+1,
    max_pos(T,M,Ind2,Res).

calc_max(L,R):-
    max_list(L,Maxi),
    max_pos(L,Maxi,1,R).

%b. repl every sublist with the pos of the max elem from that sublist
%
%
%heterList(l1..ln) = [], if n=0
%                  = calc_max(l1) + heterList(l2..ln),
%                  is_list(l1)=true
%                  =l1+heterList(l2..ln) otherwise

heterList([],[]).
heterList([H|T],[NewL|R]):- is_list(H),
    calc_max(H,NewL),
    heterList(T,R).
heterList([H|T],[H|R]):-
    heterList(T,R).





