%15. predecessor of a number represented as digits in a list
%
%
%pred(l1..ln,c) = [], if n=0
%             = l1-1, if n=1 and l1>0
%             = 9, if n=1 l1=0
%             = 9+ pred(l2..ln) , if l1=0 c=1
%             = l1-c + pred(l2..ln,c)
pred([],_,[]).
pred([A],_,[A2]):- A>0,
    A2 is A-1.
pred([0],1,[9]).
pred([0|T],1,[9|Res]):-
    pred(T,1,Res).
pred([H|T],0,[Hp|R]):-
    pred(T,C,R),
    Hp is H-C.




