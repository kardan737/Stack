#include <stdio.h>

#include "stack.h"
#include "verify.h"


int main()
    {
    my_stack stk = {};

    StackCtor(&stk, min_capasity);

    if (!StackPush(&stk, 5)) return -1;

    for (int i = 0; i < 3000; i++)
        {
        StackPush(&stk, i);
        }///////?????

    for (int i = 0; i < 3000; i++)
        {
        printf("%d " ,StackPop(&stk));
        }

    //StackDump(__);

    printf("%d " ,StackPop(&stk));

    StackDtor(&stk);

    }
