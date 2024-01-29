%a. Given a linear numerical list write a predicate to remove all
% sequences of consecutive values.


%rem_cons(l1..ln) = [], if n=0
%                 = l1, if n=1
%                 = rem_cons(l2..ln),if l2=l1+1, l3=l2+1
%                 = l2 +rem_cons(l3..ln), if l3!=l2+1
%                 = l1 +rem_cons(l2..ln), if l2!=l1+1
%

rem_cons([],[]).
rem_cons([A],[A]).
rem_cons([A,B],[]):- B=:=A+1,!.
rem_cons([A,B],[A,B]):- B=\=A+1,!.
rem_cons([H1,H2,H3|T],Res):-  1 2 3
    H2=:=H1+1,
    H3=:=H2+1,
    rem_cons([H2,H3|T],Res).
rem_cons([H1,H2,H3|T],Res):- 1 3 2
    H2=:=H1+1,
    H3=\=H2+1,
    rem_cons([H3|T],Res).
rem_cons([H1,H2,H3|T],[H1|Res]):-
    H2=\=H1+1,
    rem_cons([H2,H3|T],Res).
