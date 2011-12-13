grandfather(X,Y):-father(X,Z), parent(Z,Y).
parent(X,Y) :-father(X,Y).
parent(X,Y):-mother(X,Y).
father(james,robert).
father(mike,william).
father(william,james).
father(robert,hency).
father(robert,cris).


