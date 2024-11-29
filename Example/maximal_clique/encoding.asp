uedge(X,Y) :- edge(X,Y), X < Y.
uedge(Y,X) :- edge(X,Y), Y < X.

% guess the clique
clique(X) :- node(X), not nonClique(X).
nonClique(X) :- node(X), not clique(X).

% ensure property
:- clique(X), clique(Y), not uedge(X,Y), X < Y.

:~ nonClique(X). [1,X]
