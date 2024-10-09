#include <stdio.h>
#include <string.h>

#include "stack.h"
#include "verify.h"



int main()
    {
    my_stack stk ={};
    StackCtor(&stk, MIN_CAPASITY);

    while(1)
        {
        char cmd[50] = "";
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0)
            {
            int arg = 0;
            scanf("%d", &arg);
            StackPush(&stk, arg);
            }

        else if (strcmp(cmd, "add") == 0)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, a + b);
            }

        else if (strcmp(cmd, "sub") == 0)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, b - a);
            }

        else if (strcmp(cmd, "div") == 0)
            {
            int a = StackPop(&stk);
            int b = StackPop(&stk);
            StackPush(&stk, b / a);
            }

        else if (strcmp(cmd, "out") == 0)
            {
            printf("result = %d\n", StackPop(&stk));
            }

        else if (strcmp(cmd, "hlt") == 0)
            {
            break;
            }

        else
            {
            printf("SIN_TERROR\n");
            }

        }
    }

