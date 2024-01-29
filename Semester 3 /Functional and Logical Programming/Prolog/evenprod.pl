evenProd([],1).
evenProd([H|T],R):-
    H mod 2 =:= 0,
    evenProd(T,RT),
    R is H*RT.
evenProd([H|T],R):-
    H mod 2 =\=0,
    evenProd(T,R).
