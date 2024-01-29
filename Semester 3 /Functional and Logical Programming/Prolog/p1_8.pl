%insertn(l1..ln,e,pos) = [],if n=0
%                  = e +lpos+1..ln, if pos=0
%                  = l1 + insertn(l2..ln,e,pos-1), if

%a. Insert an element on the position n in a list.
% b. Define a predicate to determine the greatest common divisor of all
% numbers from a list

insertn([],_,_,[]).
insertn(L,E,0,[E|L]):-!.
insertn([H|T],E,P,[H|Res]):-
    P2 is P-1,
    insertn(T,E,P2,Res).

%gcd_list(l1,..ln) = l1, if n=1
%                  = gdc(l1,gdc_list(l2..ln)), otherwise
%
%
%gdc(a,b) = a, if b=0
%         = gdc(b,a%b), otherwise
%
%
gdc(A,0,A).
gdc(0,B,B).
gdc(A,B,Res):-
    Rest is A mod B,
    gdc(B,Rest,Res).

gdc_list([A],A).
gdc_list([H|T],Res):-
    gdc_list(T,Rd),
    gdc(H,Rd,Res).
