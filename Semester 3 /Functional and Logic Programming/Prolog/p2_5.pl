%a. Substitute all occurrences of an element of a list with all the
% elements of another list.
%
% subst(l1..ln,E,q1..qm) = [], if n=0
%                        = subst(append(l2,..ln,E,q1..qn), if l1=E
%                        = l1 U subst(l2..ln,E,q1..qn), if l1!=E
%

append([],L,L).
append([H|T],L,[H|Res]):-
    append(T,L,Res).

subst([],_,[_|_],[]).
subst([H|T],E,List,Res):- H=:=E,
    !,
    append(List,T,Rl),
    subst(Rl,E,List,Res).
subst([H|T],E,List,[H|Res]):- H=\=E,
    subst(T,E,List,Res).



%replace all occ of every elem from every sublist with given sublist
%
%
%heterL(l1..ln,List) = [], if n=0
%                    = subst(l1'..ln',l1,list), heterL(l2..ln),
%                    is_list(l1)=true
%                    = l1 + heterL(l2..ln)
%

heterL([],_,[]).
heterL([[H|HT]|T],L,[Hr|Res]):-  %put the new head replaced with the list2
    subst([H|HT],H,L,Hr),
    heterL(T,L,Res).
heterL([H|T],L,[H|Res]):- %put the old head
    heterL(T,L,Res).



