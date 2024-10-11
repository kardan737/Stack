#include <stdio.h>
#include <string.h>

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
    //////////////////////////////////////////////
    const char* file_name_in;

    if (argc <= 1 || argc > 3)
        file_name_in = "com.txt";
    else
        file_name_in = argv[1];

    FILE *in = fopen(file_name_in, "r");

    if (!in)
        {
        printf("OPENING_ERROR");
        return -1;
        }
    //////////////////////////////////////////////

    //////////////////////////////////////////////
    const char* file_name_out;

    if (argc <= 2 || argc > 3)
        file_name_out = "compil.txt";
    else
        file_name_out = argv[2];

    FILE* out = fopen(file_name_out, "w+");
    //////////////////////////////////////////////

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

        else if (strcmp(cmd, "mul") == 0)
            {
            fprintf(out, "%d\n", MUL);
            }

        else if (strcmp(cmd, "div") == 0)
            {
            fprintf(out, "%d\n", DIV);
            }

        else if (strcmp(cmd, "sqrt") == 0)
            {
            fprintf(out, "%d\n", SQRT);
            }

        else if (strcmp(cmd, "sin") == 0)
            {
            fprintf(out, "%d\n", SIN);
            }

        else if (strcmp(cmd, "cos") == 0)
            {
            fprintf(out, "%d\n", COS);
            }

        else if (strcmp(cmd, "in") == 0)
            {
            fprintf(out, "%d\n", IN);
            }

        else if (strcmp(cmd, "dump") == 0)
            {
            fprintf(out, "%d\n", DUMP);
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



