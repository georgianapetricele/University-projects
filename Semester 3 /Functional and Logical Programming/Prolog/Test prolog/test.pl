%return all pos of min elem from a list
%
%
%
%minim(A,B) = A, if A<B
%           = B, if A>=B
%
%minim(A:number,B:number,R:number)
%
%flow model: minim(i,i,o)
%
minim(A,B,A):- A<B.
minim(A,B,B):- A>=B.

%min_list(l1..ln) = 999, if n=0
%                 = minim(l1,min_list(l2..ln)), otherwise
%
%min_list(L:list,R:number)
%
%flow model: min_list(i,o)
%
%
min_list([],999).
min_list([H|T],R):-
    min_list(T,Rm),
    minim(H,Rm,R).

%positions_min(l1..ln,min,ind) = [], if n=0
%                              = 1, if l1=min and n=1
%                              = ind U positions_min(l2..ln,min,ind+1),
%                              if l1=min
%                              = positions_min(l2..ln,min,ind+1),
%                              otherwise
%
% positions_min(L:list,Min:number,Ind:number,R:list)
%
% flow model: positions_min(i,i,i,o)
%
positions_min([],_,_,[]).
positions_min([A],A,1,1).
positions_min([H|T],H,Ind,[Ind|Res]):-
    Ind2 is Ind+1,
    positions_min(T,H,Ind2,Res).
positions_min([H|T],Min,Ind,Res):- H =\=Min,
    Ind2 is Ind+1,
    positions_min(T,Min,Ind2,Res).


%init_positions(L:list,R:list)
%
%flow model: init_positions(i,o)
init_positions(L,R):-
    min_list(L,Min),
    positions_min(L,Min,1,R).


