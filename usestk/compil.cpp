#include <stdio.h>
#include <string.h>

enum comand
    {
    PUSH = 1,
    ADD  = 2,
    SUB  = 3,
    DIV  = 4,
    OUT = 5,
    HLT = 6,


    };

int main()
    {
    FILE* in = fopen("com.txt", "r");
    FILE* out = fopen("compil.txt", "w+");

    if (!in)
        {
        printf("OPENING_ERROR");
        return -1;
        }

    while(1)
        {
        char cmd[50] = "";
        fscanf(in, "%s", cmd);

        if (strcmp(cmd, "push") == 0)
            {
            int a = 0;

            fprintf(out, "%d ", PUSH);
            fscanf(in, "%d", &a);
            fprintf(out, "%d\n", a);
            }

        else if (strcmp(cmd, "add") == 0)
            {
            fprintf(out, "%d\n", ADD);
            }

        else if (strcmp(cmd, "sub") == 0)
            {
            fprintf(out, "%d\n", SUB);
            }

        else if (strcmp(cmd, "div") == 0)
            {
            fprintf(out, "%d\n", DIV);
            }

        else if (strcmp(cmd, "out") == 0)
            {
            fprintf(out, "%d\n", OUT);
            }

        else if (strcmp(cmd, "hlt") == 0)
            {
            fprintf(out, "%d\n", HLT);
            break;
            }

        else
            {
            printf("SIN_TERROR\n");
            }

        }
    }



