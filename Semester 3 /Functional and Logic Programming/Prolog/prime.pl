
prime(2,_).
prime(N,I):-
    I<N/2.
prime(N,I):-
    N>=N/2,
    Mod is N mod I,
    Mod =\=0,!,
    N2 is N//I,
    I2 is I+1,
    prime(N2,I2).

