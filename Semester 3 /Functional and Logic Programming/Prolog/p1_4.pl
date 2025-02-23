%.4. a. Write a predicate to determine the difference of two sets
%
% diff(l1,..ln,q1..qn) = [], n=0
%                      = diff(a2...an, b1...bn),contains(b1...bn, a1)=true
%                      = a1 + diff(a2...an, b1...bn), otherwise
%
% contains(l1..ln,E)
%                    = true, l1=E
%                    = contains(l2


contains([E|_],E):-!.
contains([_|T],E):-
    contains(T,E).


diff([],_,[]).
diff([H1|T1],B,Res):-
    contains(B,H1),
    diff(T1,B,Res), !.
diff([H1|T1],B,[H1|Res]):-
    diff(T1,B,Res).

% b. Write a predicate to add value 1 after every even element from a list.
%
% add(l1..ln)= l1+1 U add(l2..ln), if l1-even
%            = l1 U add(l2..ln), otherwise
%            = [], if n=0

add([],[]).
add([H|T],[H,1|Res]):- H mod 2 =:=0,
    add(T,Res).
add([H|T],[H|Res]):-
    add(T,Res).
