%add = e, if l empty
%    = l1 + add(e,l2..ln)


add(E,[],[E]).
add(E,[H|T],[H|Rez]):-
    add(E,T,Rez).

