% pare(l) = { 0, daca vida(l)
% { (1 - l1 % 2) + pare(l2 ... ln), altfel
% pare(L: list, Len:integer)
% L - lista pentru care trebuie aflata nr de nr pare
% Len - nr de nr pare
%
% Model de flux: (i, i) - determinist, (i, o) - determinist
% Folosim (i, o) - determinist.
pare([], 0).
pare([H|T], Len):-
   H mod 2 =:= 0,
   pare(T, Len1),
   Len is Len1+1.
pare([_|T],Len):-
    pare(T,Len).
% impare(l) = { 0, daca vida(l)
% { l1 % 2 + impare(l2 ... ln), altfel
% impare(L: list, Len:integer)
% L - lista pentru care trebuie aflata nr de nr impare
% Len - nr de nr impare
%
% Model de flux: (i, i) - determinist, (i, o) - determinist
% Folosim (i, o) - determinist.
impare([], 0).
impare([H|T], Len):-
   H mod 2 =:= 1,
   impare(T, Len1),
   Len is Len1+1.
impare([_|T],Len):-
   impare(T,Len).

% conditie(l) = { fals, pare(L) % 2 = 1 sau impare(L) % 2 = 0
% { adevarat, altfel (pare(L) % 2 = 0 si impare(L) % 2 =1)
% conditie(L: list).
% L - lista pentru care trebuie verificata conditia
% Model de flux: (i) - determinist.
conditie(L):-
 pare(L, P),
 P mod 2 =:= 0,
 impare(L, I),
 I mod 2 =:= 1.
% comb(l1,...,ln, k) = 1. [l1] daca k = 1
% 2. comb(l2,...,ln, k)
% 3. l1 + comb(l2,...,ln, k - 1) k > 1
% comb(L: list, K:integer, C:list)
% L - multimea de numere
% K - numarul de numere din combinare
% C - lista rezultat
% (i, i, o) - nedeterminist - pe acesta o sa-l folosim
% (i, i, i) - determinist
% combinariConditie(l, k) = 1. comb(l, k),
% daca conditie(comb(l, k)) - adev
% combinariConditie(L: List, K: Integer).
% L - lista pe care trebuie sa facem combinarile cu conditie
% K - numarul de elemente din combinari
% Model de flux: (i, i, i) - determinist, (i, i, o) - nedeterminist
% Folosim (i, i, o) - nedeterminist
%
%
subs([],[]).
subs([H|T],[H|R1]):-
    subs(T,R1).
subs([_|T],R1):-
    subs(T,R1).

% genereaza Lista(a, b) = { [] , a > b
% { a + genereazaLista(a+1,b), altfel
%
% genereazaLista(a:integer,b:integer,o:list)
% a - capatul inferior al intervalului
% b - capatul superior al intervalului
% o - intervalul [a,b]


genList(A,B,[]):-
    A>B,
    !.
genList(A,B,[A|R]):-
    A1 is A+1,
    genList(A1,B,R).


onesol2(A,B,RS):-
    genList(A,B,L),
    subs(L,RS),
    conditie(RS).

allsol2(A,B,R):-
    findall(R1,onesol2(A,B,R1),R).















