% sum(l1,..ln,R) = 0, if length=0
%                = l1+ sum(l2..ln)
% flow model = (i,o)

%first write the base case
sum([],0).
%then write the recursion if
sum([H|T],S):-
    sum(T,ST),
    S is ST+H.

