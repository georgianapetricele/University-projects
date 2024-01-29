%a. Transform a list in a set, in the order of the last occurrences of
% el
%
% to_set(l1..ln) = [], if n=0
%                = l1, if n=1
%                = l1 + to_set(l2..ln), if count_oc(l2..ln,l1) =0
%                = to_set(l2..ln) otherwise
%
%my_append(l1..ln,e) = e, if n=0
%                    = l1 + my_append(l2..ln,e)
%
%count_oc(l1..ln,e) = 0,if n=0
%                   = 1, if l1=e
%                   = 1+ count_oc(l2..ln,e), if l1=e
%                   =count_oc(l2)


count_oc([],_,0).
count_oc([A],A,1).
count_oc([H|T],H,R2):-
    count_oc(T,H,R),
    R2 is R+1.
count_oc([H|T],E,R):- H =\=E,
    count_oc(T,E,R).

to_set([],[]).
to_set([A],[A]).
to_set([H|T],[H|R]):-
    count_oc(T,H,Oc),
    Oc =:=0,
    to_set(T,R).
to_set([H|T],R):-
    count_oc(T,H,Oc),
    Oc =\=0,
    to_set(T,R).
