#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "verify.h"

enum comand
    {
    PUSH = 1,
    ADD  = 2,
    SUB  = 3,
    DIV  = 4,
    OUT = 5,
    HLT = 6,


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

        else if (cmd == DIV)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, b / a);
            }

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

