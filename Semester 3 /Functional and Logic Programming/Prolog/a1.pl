%f([],-1).
%f([H|T],S):-H>0,
    %f(T,S1),
    %S1<H,!,
   % S is H.
%f([_|T],S):-
 %   f(T,S1),
  %  S is S1.
%maximum
%
%
aux(S1,S,H):-
    H>0,
    S1<H,!,
    S is H.
aux(S1,S,_):-
    S is S1.

f([],-1).
f([H|T],S):-
    f(T,S1),
    aux(S1,S,H).

f2([],0).
f2([H|T],S):-
    f2(T,S1),
    S1 is S-H.

%insert(e,l1..ln) = e U l1..ln
%                 = l1 U insert(e,l2..ln)
%flow model: (i,i,o)
%
insert(E,L,[E|L]).
insert(E,[H|T],[H|R]):-
    insert(E,T,R).

%arr(l1..ln,k)= l1, if k=1
%             = arr(l2..ln,k




