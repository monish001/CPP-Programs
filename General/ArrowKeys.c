#include <stdio.h>
#include <conio.h>  /* needed for kbhit and getch *///abc hahaha		fdhnf
#include <ctype.h>  /* needed for isprint         */
int  main()
{
    int  ch;
    ch = -1;
    while (ch != 0x1B)              /* watch for an ESC */
    {
        if (kbhit() && 1)                /* check for a keystroke */
        {
            ch = getch();           /* get the key */
            printf("%02X", ch);
            if (isprint(ch)) printf("/ // /%c", ch);
            if (ch == 0)            /* if it's 0... */
            {
                ch = getch();       /* get the next key */
                printf(" \" %02X", ch);//abc
               if (isprint(ch)) printf("/%c", ch);
            }
            printf("\n");
        }
    }
    return 0;
}

