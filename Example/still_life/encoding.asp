%%% We should consider only decision version
%%% Copy in each instance value(0).
%%% Copy in each instance step(-1).
%%% Copy in each instance step(1).
%%% Add bound(B) to each instance.

value(V) :- value(V1), V=V1+1, size(N), V1<=N.

diff(X,0) :- step(X).
diff(0,Y) :- step(Y).
diff(X,Y) :- step(X), step(Y).

% a cell may live, except for the ones at the border
lives(X,Y) :- value(X), value(Y), X>0, Y>0, size(N), X<=N, Y<=N, not nlives(X,Y).
nlives(X,Y) :- value(X), value(Y), X>0, Y>0, size(N), X<=N, Y<=N, not lives(X,Y).

% cells with exactly 3 neighbours must live
%%% sum is at most one:- #sum { 1 : lives(X+DX,Y+DY), diff(DX,DY) } = 3, not lives(X,Y), value(X), value(Y).
not_lives_at_least_3(X,Y) :- #count { DX,DY : lives(XDX,YDY), XDX=X+DX, YDY=Y+DY, diff(DX,DY) } >= 3, not lives(X,Y), value(X), value(Y).
not_lives_at_most_3(X,Y) :- #count { DX,DY : lives(XDX,YDY), XDX=X+DX, YDY=Y+DY, diff(DX,DY) } <= 3, not lives(X,Y), value(X), value(Y).
:- not_lives_at_least_3(X,Y), not_lives_at_most_3(X,Y), not lives(X,Y), value(X), value(Y).

% living cells must have 2-3 living neighbours
%%% sum is at most one :- lives(X,Y), not 2 <= #sum { 1 : lives(X+DX,Y+DY), diff(DX,DY) } <= 3, value(X), value(Y).
lives_more_than_3(X,Y):-value(X), value(Y), lives(X,Y), #count{DX,DX : lives(XDX,YDY), XDX=X+DX, YDY=Y+DY, diff(DX,DY)} >3.
lives_less_than_2(X,Y):-value(X), value(Y), lives(X,Y), #count{DX,DX : lives(XDX,YDY), XDX=X+DX, YDY=Y+DY, diff(DX,DY)} <2.
:- lives(X,Y), lives_more_than_3(X,Y), value(X), value(Y).
:- lives(X,Y), lives_less_than_2(X,Y), value(X), value(Y).

% connectedness
min_set(X):-lives(X,Y), value(X), value(Y).
has_lower(X):-min_set(X),min_set(X1), X1<X.
minimum(X):-min_set(X), not has_lower(X).

min_set_y(Y):-lives(XX,Y), value(Y), minimum(X).
has_lower_y(Y):-min_set_y(Y), min_set_y(Y1), Y1<Y.
minimum_y(Y):-min_set_y(Y), not has_lower_y(Y).

reached(XX,YY) :- minimum(XX), minimum_y(YY).
reached(XX,YY) :- reached(X,Y), value(X), value(Y), diff(DX,DY), XX=X+DX, YY=Y+DY, lives(XX,YY).
:- lives(X,Y), not reached(X,Y), value(X), value(Y).

:~ value(X),value(Y), not lives(X,Y). [1,X,Y]
