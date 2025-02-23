%C. Să se scrie un program PROLOG care generează lista permutărilor
% mulţimii 1..N, cu proprietatea că valoarea absolută a
% diferenţei între 2 valori consecutive din permutare este >=2. Se vor
% scrie modelele matematice și modelele de flux pentru
% predicatele folosite.
%
%

%insert(e,l1..ln) = e U l1..ln
%                 = l1 U insert(e,l2..ln)
%flow model: (i,i,o)
%
insert(E,L,[E|L]).
insert(E,[H|T],[H|R]):-
    insert(E,T,R).

%permutations of linear list
%
%perm(l1..ln) = [], if n=0
%             = insert(l1,perm(l2..ln)), otherwise
%
%perm(L-list,R-resulted list)
%perm(i,o)
%

perm([],[]).
perm([H1|T],P):-
    perm(T,R),
    insert(H1,R,P).

%condition(A,B) = false, if A=B or abs(a-b)<2
%               = true, otherwise
% (i,i)

condition(A,A).
condition(A,B):-
    abs(A-B)>=2.

%conditionList(l1..l2) = true, if n<=2 and abs(l1-l2)>=2
%                      = false, if n<=2
%                      = condition(l1,l2) U conditionList(l2..ln)
%(i)
conditionList([A,B]):-condition(A,B).
conditionList([H1,H2|T]):-
    condition(H1,H2),
    conditionList([H2|T]).

%Determines one solution
%L:list, RP:list, resulted permutation
%(i,o)
onesol(L,RP):-
    perm(L,RP),
    conditionList(RP).

% Determines all solutions for our problem using the predefines
% predicated FINDALL
% allsol(L:list,R:list results)
% (i,o)
allsol(L,R):-
    findall(X,onesol(L,X),R).


arr([E|_],1,[E]).
arr([_|T],K,R) :-
    arr(T,K,R).
arr([H|T],K,R1):-
    K>1,
    K1 is K-1,
    arr(T,K1,R),
    insert(H,R,R1).


%onesol(L,K,P,S,RL):-
%   arr(L,K,RL),
%    pr(RL,1,P),
%    suma(RL,0,S).

%allsol(L,K,P,S,R):-
%    findall(RL,onesol(L,K,P,S,RL),R).

