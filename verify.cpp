#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "verify.h"

bool StackAssert(my_stack* stk)
    {
    if (stk == nullptr)
        {
        printf("stack was not declarated");
        return false;
        }

    if (stk->addr == nullptr)
        {
        printf("null addr stack");
        return false;
        }

    if (stk->sizee < 0)
        {
        printf("size less than zero");
        return false;
        }

    if (stk->sizee > stk->capasity)
        {
        printf("capasity less than size");
        return false;
        }

    if (stk->capasity < min_capasity)
        {
        printf("capasity less than min size capasity");
        return false;
        }

    return true;
    }


/*void StackDump(my_stack* stk, char* file, char* func, int line)
    {
    printf("Error in file <%s>;in function <%s>;in line <%d>", file, func, line);

    printf("Problem in:");

    if (stk == nullptr)
        printf("stack ");

    if (stk->error == ADDR)
        printf("ADDR was not declarated");

    if (stk->error == SIZEE)
        printf("ADDR was not declarated");

    if (stk->error == CAPASITY)
        printf("ADDR was not declarated");

    printf();

    }*/

