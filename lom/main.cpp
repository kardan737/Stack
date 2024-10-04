#include <stdio.h>

#include "stack.h"
#include "verify.h"


int main()
    {
    my_stack stk = {};

    StackCtor(&stk, min_capasity);

    //StackPush(&stk, i);

    //StackDump(__);  <---не робит

    //printf("%d " ,StackPop(&stk));

    StackDtor(&stk);

    }
