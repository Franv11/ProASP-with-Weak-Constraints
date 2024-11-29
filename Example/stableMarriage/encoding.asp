% guess matching
match(M,W) :- manAssignsScore(M,X,Y), womanAssignsScore(W,Z,V), not nonMatch(M,W).
nonMatch(M,W) :- manAssignsScore(M,X,Y), womanAssignsScore(W,X,V), not match(M,W).

:~ manAssignsScore(M,X,Y), not jailed(M). [1,M]

% no singles
jailed(M) :- match(M,X).

% no polygamy
:- match(M1,W), match(M,W), M != M1.
:- match(M,W), match(M,W1), W != W1.

:- womanAssignsScore(W,M,Swm), match(M1,W), match(M,W1), manAssignsScore(M,W,Smw), womanAssignsScore(W,M1,Swm1),
manAssignsScore(M,W1,Smw1), W1 != W, Smw > Smw1, Swm >= Swm1.