fact(1,1).
fact(0,1).
fact(IN,OUT):-IN1 is IN-1,fact(IN1,OutPrev),OUT is OutPrev*IN.
