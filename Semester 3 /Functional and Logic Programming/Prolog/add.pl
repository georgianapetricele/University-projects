%add a value E on position M in a given list
%addE(E-val,M-pos,[]-initial list,[]-resulted list
%flow: (i,i,i,o),(o,i,i,i),(i,o,i,i),(i,i,o,i)
%add = empty, n=0, m>1
%    = [e], n=0 m=1
%    =  e U []  , n>0 m=1
%    =  l1 U add(l2..ln,E,m-1)  n>0 m>1 dec m to get to the

%use if we have more base cases
addE(E,M,[],[E]):- M=:=1.
addE(_,M,[],[]):- M>1.
addE(E,M,L,R):- M=:=1,
    R=[E|L].
addE(E,M,[H|T],[H|R]):- M>1,
    M1 is M-1,
    addE(E,M1,T,R).
