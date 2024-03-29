%C. Write a PROLOG program that generates the list of all subsets of k
% elements in arithmetic
% progression. Write the mathematical models and flow models for the
% predicates used. For
% example, for L=[1,5,2,9,3] and k=3 ⇒ [[1,2,3],[1,5,9],[1,3,5]] (not
% necessarily in this order).

subs2([],[]).
subs2([H|T],[H|R]):-
    subs2(T,R).
subs2([_|T],R):-
    subs2(T,R).


check([_,_]):-!.
check([H1,H2,H3|T]):-
    R1 is H2-H1,
    R2 is H3-H2,
    R1 =:= R2,
    check([H2,H3|T]).

comb([H|_],1,[H]).
comb([H|T],K,[H|R]):-
    K>1,
    K1 is K-1,
    comb(T,K1,R).
comb([_|T],K,R):-
    comb(T,K,R).

consec([]).
consec([H1,H2|T]):-
    H1<H2,
    consec([H2|T]).

onesol(L,K,RC):-
    comb(L,K,RC),
    %consec(RC),
    check(RC).



