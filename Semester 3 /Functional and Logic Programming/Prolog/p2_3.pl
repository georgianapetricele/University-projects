%.
%a. Merge two sorted lists with removing the double values.
%

%merge(l1..ln,q1..qn) = [],if n=0 and m=0
%                     = l1..ln, if m=0
%                     = q1..qn, if n=0


merge1([],[],[]).
merge1([],L2,L2).
merge1(L1,[],L1).
merge1([H1|T1],[H2|T2],[H1|Rez]):-
    H1<H2,
    merge1(T1,[H2|T2],Rez).
merge1([H1|T1],[H2|T2],[H2|Rez]):-
    H2<H1,
    merge1([H1|T1],T2,Rez).
merge1([H1|T1],[H2|T2],Rez):- H1=H2,
    merge1([H1|T1],T2,Rez).

%b. merge all sublists with removing the double values.
%
%merge_list(l1,...ln) = [], n=0
%                     = merge(l1, merge_list(l2,..ln)), if
%                     is_list(l1)=true
%                     = merge_list(l2,..ln), otherwise
%
merge_list([],[]).
merge_list([H|T],Rez):- is_list(H),
    merge_list(T,R2),
    merge1(H,R2,Rez).
merge_list([_|T],Rez):-
    merge_list(T,Rez).
