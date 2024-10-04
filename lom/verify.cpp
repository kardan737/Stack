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
        stk->error = false;
        printf("null addr stack");
        return false;
        }

    if (stk->sizee > stk->capasity)
        {
        stk->error = false;
        printf("capasity less than size");
        return false;
        }

    if (stk->capasity < min_capasity)
        {
        stk->error = false;
        printf("capasity less than min size capasity");
        return false;
        }

    return true;
    }


/*void StackDump(my_stack* stk, char* file, char* func, int line)
    {
    if
    printf("Error in file <%s>;in function <%s>;in line <%d>", file, func, line);

    printf("Problem in:");

    StackAssert(stk);

    printf("addr stack: <%>", .....);
    printf("capasity stack: <%>", .....);
    printf("size stack: <%>", .....);

    }*/
