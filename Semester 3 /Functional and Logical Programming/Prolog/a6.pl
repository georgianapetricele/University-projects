%4
f2([],[]).
f2([H|T],[H|S]):-
    f2(T,S).
f2([H|T],S):-
    H mod 2 =:= 0,
    f2(T,S).

main(L,R):-
    findall(R1,f2(L,R1),R).
%2
f([],0).
f([H|T],S):-
    f(T,S1),
    S1<H,!,
    S is H.
f([_|T],S):-
    f(T,S1),
    S is S1.

%determines the maximum element
%
%faux(H:integer,S:integer,S1:integer)
%(i,i,o) -det
faux(H,S,S1):-
    S1<H,!,
    S is H.
faux(_,S1,S1).

%f3(L:list of nr,S:Number)
%(i,o)
f3([],0).
f3([H|T],S):-
    f(T,S1),
    faux(H,S,S1).




