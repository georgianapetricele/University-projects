
aux(H,S,S1):-
    H<S1,!,
    S is H+S1.
aux(_,S,S1):-
    S is S1+2.

f([],0).
f([H|T],S):-
    f(T,S1),
    aux(H,S,S1).

f2([],0).
f2([H|T],S):-
    f2(T,S1),
    H<S1,!,
    S is H+S1.
f2([_|T],S):-
    f2(T,S1),
    S is S1+2.


p(1).
p(2).
q(1).
q(2).
r(1).
r(2).

s:-p(X),!,q(Y),r(Z), write(X), write(Y), write(Z),nl.

%3. nr of subsets with nr elems >=n, each having sum % 3
%
%
apare(E,[E|_]):-!.
apare(E,[_|T]):-apare(E,T).

%subsets of a list
%
%subs(l1..ln)= [],if n=0
%            = l1 U subs(l2..ln),n>0
%            = subs(l2..ln)
subs([],[]).
subs([H|T],[H|R]):-
   % not(apare(H,T)),
    subs(T,R).
subs([_|T],R):-
    subs(T,R).

%lenList(l1..ln) = 0, if n=0
%               = 1 + lenList(l2..ln), otherwise
%
lenList([],0).
lenList([_|T],R):-
    lenList(T,R1),
    R is 1+R1.

sumList([],0).
sumList([H|T],R):-
    sumList(T,R1),
    R is R1+H.

oneSol(L,N,Sub):-
    subs(L,Sub),
    lenList(Sub,Len),
    Len >= N,
    sumList(Sub,Sum),
    Sum mod 3 =:= 0.

allSol(L,N,R):-
    findall(RPar,oneSol(L,N,RPar),R).
