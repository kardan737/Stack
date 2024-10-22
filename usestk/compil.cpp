#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/processor.h"


int main(int argc, char* argv[])
    {
    ass_mas ass_massa = {};
    //////////////////////////////////////////////
    const char* file_name_in = {};
    const char* file_name_out = {};

    if (argc <= 1 || argc > 3)
        file_name_in = "../file/com.txt";
    else
        file_name_in = argv[1];

    if (argc <= 2 || argc > 3)
        file_name_out = "../file/compil.txt";
    else
        file_name_out = argv[2];

    FILE *in = fopen(file_name_in, "r");
    if (!in)
        {
        printf("OPENING_IN_ERROR");
        return -1;
        }

    FILE* out = fopen(file_name_out, "wb+");
    if (!out)
        {
        printf("OPENING_OUT_ERROR");
        return -1;
        }
    //////////////////////////////////////////////

    ass_massa.code = (int*)calloc(10, sizeof(int));     // size of file
    if (ass_massa.code == NULL)
        {
        printf("MEMORY_ALLOCATION_ERROR");
        return -1;
        }

    ass_massa.capacity = 10;
    ass_massa.sizee = 0;
    //////////////////////////////

    while(1)
        {
        char cmd[50] = "";
        fscanf(in, "%s", cmd);

        if (ass_massa.sizee >= ass_massa.capacity)
            {
            ass_massa.capacity = ass_massa.capacity * 2;
            ass_massa.code = (int*)realloc(ass_massa.code, sizeof(int) * ass_massa.capacity);
            if (ass_massa.code == NULL)
                {
                printf("MEMORY_ALLOCATION_ERROR");
                    return -1;
                }
            }

        if (strcmp(cmd, "push") == 0)
            {
            int a = 0;

            ass_massa.code[ass_massa.sizee++] = PUSH;
            fscanf(in, "%d", &a);
            ass_massa.code[ass_massa.sizee++] = a;
            }

        else if (strcmp(cmd, "add") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = ADD;
            }

        else if (strcmp(cmd, "sub") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = SUB;
            }

        else if (strcmp(cmd, "mul") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = MUL;
            }

        else if (strcmp(cmd, "div") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = DIV;
            }

        else if (strcmp(cmd, "sqrt") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = SQRT;
            }

        else if (strcmp(cmd, "sin") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = SIN;
            }

        else if (strcmp(cmd, "cos") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = COS;
            }

        else if (strcmp(cmd, "in") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = IN;
            }

        else if (strcmp(cmd, "dump") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = DUMP;
            }

        else if (strcmp(cmd, "out") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = OUT;
            }

        else if (strcmp(cmd, "hlt") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = HLT;
            break;
            }

        else
            printf("SIN_TERROR\n");

        }

    signature head = { 0x584F4C444544, 2, --ass_massa.sizee};

    fwrite(&head, 1, sizeof(signature), out);
    fwrite(ass_massa.code, 1, sizeof(int) * ass_massa.sizee, out);

    free(ass_massa.code);
    fclose(in);
    fclose(out);
    }



