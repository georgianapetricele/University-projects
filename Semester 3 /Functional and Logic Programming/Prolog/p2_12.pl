%a. add after every element from a list, the divisors of that number.

gen_divisors(N,_,L,L):- N=<2.
gen_divisors(N,N,L,L).
gen_divisors(N,Div,L,[Div|Res]):-
    N mod Div =:=0,
    NewD is Div+1,
    gen_divisors(N,NewD,L,Res).
gen_divisors(N,Div,L,Res):-
    NewD is Div+1,
    gen_divisors(N,NewD,L,Res).

my_append([],L,L).
my_append([H1|T1],L2,[H1|R]):-
    my_append(T1,L2,R).

add_div([],[]).
add_div([H|T],[H|RDiv]):-
    add_div(T,R),
    gen_divisors(H,2,R,RDiv).
