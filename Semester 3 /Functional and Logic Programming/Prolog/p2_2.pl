%2.
% a. Sort a list with keeping double values in resulted list. E.g.: [4 2
% 6 2 3 4] --> [% 2.
% a. Sort a list with keeping double values in resulted list.
% E.g.: [4 2 6 2 3 4] --> [2 2 3 4 4 6]


% merge(l1...ln, r1...rm) = -> l1...ln, m = 0
%                           -> r1...rn, n = 0
%                           -> l1 + merge(l2...ln, r1...rm), l1 <= r1
%                           -> r1 + merge(l1...ln, r2...rm), l1 > r1

% my_merge(L:list, R:list, R:list)
% flow model: my_merge(i, i, o)
merge([],L,L).
merge(R,[],R).
merge([A|T1],[B|T2],[A|L2]) :-
      A =< B,
      merge(T1,[B|T2],L2).
merge([A|T1],[B|T2],[B|L2]) :-
      A > B,
      merge([A|T1],T2,L2).



%split(l1,..,ln) = -> [], if n=0
%                  -> l1, if n=1
%                  -> split(l1,..l(n/2),l(n/2+1)..l(n))
%
%split(List:Initial list,L:Left sublist,R:Right sublist)
%flow model: (i,o,o)
split([],[],[]).
split([A],[A],[]).
split([A,B|T],[A|P1],[B|P2]) :-
     split(T,P1,P2).


% mergeSort(l1...ln) = -> [], if n=0
%	                -> [l1], n = 1
%                       -> merge( mergeSort(l1....l(n/2)),
%            mergeSort(l(n/2+1)...ln)), otherwise

% mergeSort(L1:Input list, L2:Output list)
% flow model: (i, o)
%
% examples:
% mergeSort([5,3,3,2,1,3],LR).
% LR=[1, 2, 3, 3, 3, 5]

mergeSort([],[]).
mergeSort([A],[A]).
mergeSort(L1,L2) :-
     split(L1,P1,P2),  %split in 2 parts
     mergeSort(P1,S1),  %merge sort in left part
     mergeSort(P2,S2),  %merge sort in right part
     merge(S1,S2,L2).   %merge them



%b. For a heterogeneous list, formed from integer numbers and list of numbers, write a predicate to sort every
%sublist, keeping the doubles.
%Eg.: [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] =>
%[1, 2, [1, 4, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1, 1, 1], 7].

%heterList(l1,..,ln) = -> [],if n=0
%                      -> mergeSort(l1)+ heterList(l2,..,ln), if
%                      is_list=true
%                      ->l1+heterList(l2,..,ln), otherwise
%
%heterList(L:List,R:Output List)
%flow model: (i,o)


heterList([],[]).
heterList([H|T],[HR|R]):-
    is_list(H),
    !,
    mergeSort(H,HR),
    heterList(T,R).
heterList([H|T],[H|R]):-
    heterList(T,R).














