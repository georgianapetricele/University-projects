%longest sequences of consecutive even numbers (if exist more maximal
%sequences one of them).


%even_seq(l1..ln,m1..mn,aux1..auxn) = [], if n=0
%                 = m1..mn, if len(m)>=len(aux)
%                 = aux1..auxn, len(aux)>
%                 = l1 +even_seq(l2..ln,m1..mn,l1+aux1..auxk), if l1 mod
%                 2 =0
%                 = even_seq(l2..ln,m1..mn,[] ) if l1mod2!=0 and
%                 len(m)>=len(aux)
%                 =even_seq(l2..ln,aux1..auxn,[] ) if l1mod2!=0 and
%                 len(m)>=len(aux)
%

consecutive([], C, AUX, C) :-
    my_length(C, RC),
    my_length(AUX, RAUX),
    RC >= RAUX.
consecutive([], C, AUX, AUX) :-
    my_length(C, RC),
    my_length(AUX, RAUX),
    RC < RAUX.
consecutive([H|T], C, AUX, R) :- even(H),
    my_append(AUX, H, RA),
    consecutive(T, C, RA, R).
consecutive([_|T], C, AUX, R) :-
    my_length(C, RC),
    my_length(AUX, RAUX),
    RAUX >= RC,
    consecutive(T, AUX, [], R).
consecutive([_|T], C, AUX, R) :-
    my_length(C, RC),
    my_length(AUX, RAUX),
    RAUX < RC,
    consecutive(T, C, [], R).
