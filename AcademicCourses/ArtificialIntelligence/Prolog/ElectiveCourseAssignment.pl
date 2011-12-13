consultation:- init_database,
	writeln('Welcome to Elective Course Assignment System in Thapar'),
	writeln('Enter your name'),read(Name),nl,
	check(Course),!,write('Notice: '),write(Name),
	write('!! You have been assigned to '),
	writeln(Course),write('!'),nl,write('Thanks for using this system.'),clear_consult_facts.

consultation:- writeln('Sorry,not able to find the course assigned'),clear_consult_facts.
init_database:-assert(positive(x)),assert(negative(y)).
check(advOs):-requirement(os),requirement(ds).
check(advAi):-requirement(ai).
check(dataMining):-requirement(dbms).
check(dataWarehouse):-requirement(dataMining),requirement(dbms).
requirement(os):-positive_requ('Have you done Operating System(y/n)?',os).
requirement(ds):-positive_requ('Have you done Data Structures(y/n)?',ds).
requirement(ai):-positive_requ('Have you done Aritificial Intelligence(y/n)?',ai).
requirement(dbms):-positive_requ('Have you done DBMS(y/n)?',dbms).
requirement(dataMining):-positive_requ('Have you done Data Mining(y/n)?',dataMining).
positive_requ(_,X):-positive(X),!.
positive_requ(Q,X):-not(negative(X)),ask_query(Q,X,R),R='y'.
ask_query(Q,X,R):-writeln(Q),read(R),nl,store(X,R).
store(X,'y'):-asserta(positive(X)).
store(X,'n'):-asserta(negative(X)).
clear_consult_facts:-retractall(positive(_)),retractall(negative(_)).











