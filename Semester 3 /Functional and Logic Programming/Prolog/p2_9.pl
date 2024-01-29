% add in list after 1-st, 3-rd, 7-th, 15-th element a given value e.
%
%
% add on pos 2^p
%
%
% add(l1..ln,Ind,P,E) = [],if n=0
%                   = [l1,E], if n=1
%                   = E+ add(l2..ln,Ind+1,P*2,E), if Ind=P
%                   = add(l2..ln,Ind+1,P,E), otherwise
%
%
add([],_,_,_,[]).
add([H],_,_,E,[H,E]).
add([H|T],Ind,P,E,[H,E|Res]):- Ind=:=P-1,
    Ind2 is Ind+1,
    P2 is P*2,
    add(T,Ind2,P2,E,Res).
add([H|T],Ind,P,E,[H|Res]):-
     Ind2 is Ind+1,
     add(T,Ind2,P,E,Res).


main([],_,[]).
main(L,E,R):-
    add(L,1,2,E,R).

% b.add in every sublist after 1-st, 3-rd, 7-th, 15-th element the value
% fo%und before the sublist in the heterogenous list

heterList([],[]).
heterList([H1,H2|T],[H1,Radd|R]):- is_list(H2), number(H1),
    add(H2,1,2,H1,Radd),
    heterList(T,R).
heterList([H|T],[H|R]):-
    heterList(T,R).

