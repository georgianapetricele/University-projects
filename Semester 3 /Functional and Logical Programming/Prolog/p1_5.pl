%5. a. Write a predicate to compute the union of two sets.
%

%union(l1..ln,q1..qn) = [], n=0 and m=0
%                     = l1 + union(remOc2(l1..ln,l1),remOc2(q1..qm,l1)),
%                     n>0
%                     = union(q1..qm,[]), n=0

%remOc(l1..ln,E) = [],if n=0
%              = remOc(l2,..ln), if l1=E
%              = l1 U remOc(l2,..ln)
%
%
remOc2([], _, []).
remOc2([E|T], E, Res) :-
    remOc2(T, E, Res).
remOc2([H|T], E, [H|Res]) :-
    H \= E,
    remOc2(T, E, Res).

union([], [], []).
union(A,[],A):-!.
union([],B,B):-!.
union([H|T], B, [H|Res]) :-
    remOc2(T, H, R1),
    remOc2(B, H, R2),
    union(R1, R2, Res).

% b. Write a predicate to determine the set of all the pairs of elements
% in a list.
%Eg.: L = [a b c d] => [[a b] [a c] [a d] [b c] [b d] [c d]]

%gen all the pairs with findall
%
%pair = [],if k=0
%     = l1+pair(l2..ln,k-1), k>0
%     = pair(l2,..ln,k) , k>0 include first elem in the rec
pair([],0,[]).
pair([H|T],K,[H|Res]):-
    K1 is K-1,
    pair(T,K1,Res).
pair([_|T], K, R) :-
    pair(T, K, R).

gen_sets([],[]).
gen_sets(L,R):-
    findall(Rl,pair(L,2,Rl),R).





