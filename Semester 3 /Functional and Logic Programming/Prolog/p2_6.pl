%6. a. Determine the product of a number represented as digits in a list
% to a given digit.

%prod(l1..ln,D,C) = [C], if n=0
%               = (l1*D+c)%10+prod(l2..ln,D,(l1*D+C)/10),otherwise
%
%
% my_append(l1..ln,E) = [E], if n=0
%                     = l1+my_append(l2..ln), ot
%
%inv_list(l1..ln) = [], if n=0
%                 = my_append(l2..ln,l1), otherwise
%
%
my_append([],E,[E]).
my_append([H|T],E,[H|Res]):-
    my_append(T,E,Res).


inv([],[]).
inv([H|T],R):-
    inv(T,Rl), %go with the recursion until last elem
    my_append(Rl,H,R). %add it at result

prod([],_,0,[]).
prod([],_,C,[C]):- C=\=0.
prod([H|T],D,C,[H1|Res]):-
    H1 is (H*D+C) mod 10,
    C1 is (H*D+C-H1)/10,
    prod(T,D,C1,Res).


main(L,D,R):-
    inv(L,Inv),
    prod(Inv,D,0,P),  %C=0 carry
    inv(P,R).


