#include <stdio.h>
#include <string.h>
#include <math.h>

#include "stack.h"
#include "verify.h"

enum comand
    {
    PUSH = 1,
    ADD  = 2,
    SUB  = 3,
    MUL  = 4,
    DIV  = 5,
    SQRT = 6,
    SIN  = 7,
    COS  = 8,
    IN   = 9,
    DUMP = 10,
    OUT  = 11,
    HLT  = 13,
    };

int main(int argc, char* argv[])
    {
    my_stack stk ={};
    StackCtor(&stk, MIN_CAPASITY);

    const char* instruction;

    if (argc != 2)
        instruction = "compil.txt";
    else
        instruction = argv[1];

    FILE *in = fopen(instruction, "r");

    if (!in)
        {
        printf("OPENING_ERROR");
        return -1;
        }

    while(1)
        {
        int cmd = 0;
        fscanf(in, "%d", &cmd);

        if (cmd == PUSH)
            {
            int arg = 0;
            fscanf(in, "%d", &arg);
            StackPush(&stk, arg);
            }

        else if (cmd == ADD)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, a + b);
            }

        else if (cmd == SUB)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, b - a);
            }

        else if (cmd == MUL)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, a * b);
            }

        else if (cmd == DIV)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, b / a);
            }

        else if (cmd == SQRT)
            {
            int a = StackPop(&stk);
            StackPush(&stk, sqrt(a));
            }

        else if (cmd == SIN)
            {
            int a = StackPop(&stk);
            StackPush(&stk, sin(a));
            }

        else if (cmd == COS)
            {
            int a = StackPop(&stk);
            StackPush(&stk, cos(a));
            }

        else if (cmd == IN)
            {
            int a = 0;
            scanf("enter a number: %d", &a);
            StackPush(&stk, a);
            }

        /*else if (cmd == DUMP)
            {
            StackDump(&stk);
            }*/

        else if (cmd == OUT)
            {
            printf("result = %d\n", StackPop(&stk));
            }

        else if (cmd == HLT)
            {
            break;
            }

        else
            {
            printf("SIN_TERROR\n");
            break;
            }

        }
    }

