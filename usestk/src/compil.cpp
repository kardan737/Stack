#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/processor.h"

int OpenFiles(FILE** in, FILE** out, int argc, char* argv[]);
int AssMassaCtor(ass_mas* ass_massa);
int checkMark(char* cmd, bool inComand, listMarks* lm, ass_mas ass_massa, listMarks* postCompil);
int PostCompil(ass_mas* ass_massa, listMarks lm, listMarks postCompil);


int main(int argc, char* argv[])
    {
    ////////////////////////////////
    FILE* in;
    FILE* out;

    OpenFiles(&in, &out, argc, argv);
    ////////////////////////////////
    ass_mas ass_massa = {};

    AssMassaCtor(&ass_massa);
    ////////////////////////////////
    listMarks lm = {};
    lm.index = 0;

    listMarks postCompil = {};
    postCompil.index = 0;

    int flagPostCompil = 0;

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

        else if (strchr(cmd, ';') > 0)
            {

            flagPostCompil = checkMark(cmd, false, &lm, ass_massa, &postCompil);
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

        else if (strcmp(cmd, "ja") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JA;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "jae") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JAE;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "jb") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JB;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "jbe") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JBE;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "je") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JE;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "jne") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JNE;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "jmp") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = JMP;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "hlt") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = HLT;
            break;
            }

        else
            printf("SIN_TERROR\n");

        }

    /*for (int i = 0; i < lm.index; i++)
        {printf("%s", lm.listt[i].name);
                printf("%d", lm.listt[i].index);} */

    if (flagPostCompil > 0)
        PostCompil(&ass_massa, lm, postCompil);

    signature head = { 0x584F4C444544, 2, ass_massa.sizee};

    fwrite(&head, 1, sizeof(signature), out);
    fwrite(ass_massa.code, 1, sizeof(int) * ass_massa.sizee, out);

    free(ass_massa.code);
    fclose(in);
    fclose(out);
    }



int OpenFiles(FILE** in, FILE** out, int argc, char* argv[])
    {
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

    *in = fopen(file_name_in, "r");
    if (!in)
        {
        printf("OPENING_IN_ERROR");
        return -1;
        }

    *out = fopen(file_name_out, "wb+");
    if (!out)
        {
        printf("OPENING_OUT_ERROR");
        return -1;
        }
    }

int AssMassaCtor(ass_mas* ass_massa)
    {
    ass_massa->code = (int*)calloc(MIN_CAPASITYY, sizeof(int));
    if (ass_massa->code == NULL)
        {
        printf("MEMORY_ALLOCATION_ERROR");
        return -1;
        }

    ass_massa->capacity = MIN_CAPASITYY;
    ass_massa->sizee = 0;
    }

int checkMark(char* cmd, bool inComand, listMarks* lm, ass_mas ass_massa, listMarks* postCompil)
    {
    if (inComand == true)
        {
        for( int i = 0; i < lm->index; i++)
            {
            if (strcmp(lm->listt[i].name, cmd) == 0)
                return lm->listt[i].index;
            }
        strcpy(lm->listt[lm->index].name, cmd);
        lm->listt[lm->index].index = -1;

        strcpy(postCompil->listt[postCompil->index].name,  cmd);
        postCompil->listt[postCompil->index++].index = ass_massa.sizee - 1;

        return lm->listt[lm->index++].index;
        }

    if (inComand == false)
        {
        for( int i = 0; i < lm->index; i++)
            {
            if (strcmp(lm->listt[i].name, cmd) == 0)
                {
                lm->listt[i].index = ass_massa.sizee;
                return 1;
                }
            }
        strcpy(lm->listt[lm->index].name,  cmd);
        lm->listt[lm->index++].index = ass_massa.sizee;
        return 0;
        }
    }

int PostCompil(ass_mas* ass_massa, listMarks lm, listMarks postCompil)
    {
    for (int i = 0; i < postCompil.index; i++)
        {
        for (int j = 0; j < lm.index; j++)
            {
            if (strcmp(lm.listt[j].name, postCompil.listt[i].name) == 0)
                {
                ass_massa->code[postCompil.listt[i].index] = lm.listt[j].index;
                }
            }
        }
    return 0;
    }


