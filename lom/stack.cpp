#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "verify.h"


bool StackCtor(my_stack* stk, int min_capasity)
    {
    assert(stk != nullptr);

    stk->addr = (int*)calloc(min_capasity, sizeof(int));

    if (stk->addr == nullptr)
        {
        printf("NULL_CTOR_ADDR");
        return false;
        }

    stk->capasity = min_capasity;
    stk->sizee = 0;
    stk->error = true;

    return StackAssert(stk);

    }


bool StackPush(my_stack* stk, int new_element)
    {
    if (!StackAssert) return false;

    if (stk->sizee == stk->capasity)
        ExtendMemory(stk);

    stk->addr[stk->sizee] = new_element;

    stk->sizee++;

    if (!StackAssert) return false;

    return true;
    }


int StackPop(my_stack* stk)
    {
    if (!StackAssert) return false;

    if ((stk->sizee * 4 <= stk->capasity) && (stk->sizee >= min_capasity))
        StackCut(stk);

    stk->sizee--;
    int x = stk->addr[stk->sizee];

    if (!StackAssert) return false;

    return x;
    }


bool ExtendMemory(my_stack* stk)
    {
    if (!StackAssert) return false;

    stk->capasity = stk->capasity * 2;
    int* old_addr = stk->addr;
    stk->addr = (int*)realloc(old_addr, sizeof(int) * stk->capasity);

    if (!StackAssert) return false;

    return true;
    }


bool StackCut(my_stack* stk)
    {
    if (!StackAssert) return false;

    stk->capasity = stk->capasity / 4;
    int* old_addr = stk->addr;
    stk->addr = (int*)realloc(stk->addr, sizeof(int) * stk->capasity);

    if (!StackAssert) return false;

    return true;
    }


bool StackDtor(my_stack* stk)
    {
    if (!StackAssert) return false;

    free(stk);
    return true;
    }

