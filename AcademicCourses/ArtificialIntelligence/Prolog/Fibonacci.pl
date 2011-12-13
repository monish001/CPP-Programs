fib(1,1).
fib(2,1).
fib(N,VAL):-N1 is N-1, N2 is N-2, fib(N1,F1), fib(N2,F2), VAL is F1+F2.
