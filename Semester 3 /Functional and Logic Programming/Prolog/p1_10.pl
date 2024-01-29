%.a.
%
%valley(l1..ln,f) = true, if n=1
%                 = valley(l2..ln,1), if l1>l2 anf f=1
%                 = valley(l2..ln,0), if l1=<l2 and f=1
%                 = valley(l2..ln,0) if l1<l2 and f=0
%                 = false otherwise
%


valley([],0).
valley([_],0).
valley([H1,H2|T],1):- H1>H2,
    valley([H2|T],1).
valley([H1,H2|T],1):- H1=<H2,
    valley([H2|T],0).
valley([H1,H2|T],0):- H1<H2,
    valley([H2|T],0).


%b. Calculate the alternate sum of list’s elements (l1 - l2 + l3 ...)
%
%
%alternate_sum(l1..ln) = 0, if n=0
%                      = l1, if n=1
%                      = l1-l2, if n=2
%                      = l1-l2+alternate(l3..ln)
%
alternate_sum([],0).
alternate_sum([A],A).
alternate_sum([H1,H2|T],R2):-
    alternate_sum(T,R),
    R2 is H1-H2+R.

