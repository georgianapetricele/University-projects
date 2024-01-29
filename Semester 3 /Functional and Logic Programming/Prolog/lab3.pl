f(0,_,[]).
f(N,C,[C|T]):-
    N>=C,
    N1 is N-C,
    C1 is C+1,
    f(N1,C1,T).
f(N,C,T):-
    N>C,
    C1 is C+1,
    f(N,C1,T).

% f(N,c)= []
%       = C U f(N-C,C+1), n>=C
%       = f(N,C+1), N>C
