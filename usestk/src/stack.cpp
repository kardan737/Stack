#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../headers/stack.h"
#include "../headers/verify.h"


bool StackCtor(my_stack* stk, int MIN_CAPASITY)
    {
    assert(stk != nullptr);

    stk->addr = (int*)calloc(MIN_CAPASITY, sizeof(int));

    if (stk->addr == nullptr)
        {
        printf("NULL_CTOR_ADDR");
        return false;
        }

    stk->capasity = MIN_CAPASITY;
    stk->sizee = 0;
    stk->error = true;

    stk->left_struct_chica = COCK;
    stk->right_struct_chica = COCK;

    return StackAssert(stk);

    }


bool StackPush(my_stack* stk, int new_element)
    {
    if (!StackAssert(stk)) return false;

    if (stk->sizee == stk->capasity)
        ExtendMemory(stk);

    stk->addr[stk->sizee] = new_element;

    stk->sizee++;

    if (!StackAssert(stk)) return false;

    return true;
    }


int StackPop(my_stack* stk)
    {
    if (!StackAssert(stk)) return false;
    if (stk->sizee == 0)
        {
        printf("ZERO_STACK");
        return -1;   ////////////////////??????????????????
        }


    if ((stk->sizee * 4 <= stk->capasity) && (stk->sizee >= MIN_CAPASITY))
        StackCut(stk);

    stk->sizee--;
    int x = stk->addr[stk->sizee];

    if (!StackAssert(stk)) return false;

    return x;
    }


bool ExtendMemory(my_stack* stk)
    {
    if (!StackAssert(stk)) return false;

    stk->capasity = stk->capasity * 2;
    int* old_addr = stk->addr;
    stk->addr = (int*)realloc(old_addr, sizeof(int) * stk->capasity);

    if (stk->addr == nullptr)
        {
        printf("NULL_CTOR_ADDR(EXTEND_MEMORY)");
        return false;
        }

    if (!StackAssert(stk)) return false;

    return true;
    }


bool StackCut(my_stack* stk)
    {
    if (!StackAssert(stk)) return false;

    stk->capasity = stk->capasity / 2;
    int* old_addr = stk->addr;
    stk->addr = (int*)realloc(stk->addr, sizeof(int) * stk->capasity);

    if (stk->addr == nullptr)
        {
        printf("NULL_CTOR_ADDR(STACK_CUT)");
        return false;
        }

    if (!StackAssert(stk)) return false;

    return true;
    }


bool StackDtor(my_stack* stk)
    {
    if (!StackAssert(stk)) return false;

    free(stk);
    return true;

}

