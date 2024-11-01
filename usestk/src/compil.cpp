#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/processor.h"

int OpenFiles(FILE** in, FILE** out, int argc, char* argv[]);
int AssMassaCtor(ass_mas* ass_massa);
int checkMark(char* cmd, bool inComand, listMarks* lm, ass_mas ass_massa, listMarks* postCompil);
int PostCompil(ass_mas* ass_massa, listMarks lm, listMarks postCompil);
int StrAnalysisPush(ass_mas* ass_massa, char* cmd);
int StrAnalysisPop(ass_mas* ass_massa, char* cmd);


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

        if (ass_massa.sizee - 3 >= ass_massa.capasity)
            {
            ass_massa.capasity = ass_massa.capasity * 2;
            ass_massa.code = (int*)realloc(ass_massa.code, sizeof(int) * ass_massa.capasity);
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
            fgets(cmd, 50, in);
            if (StrAnalysisPush(&ass_massa, cmd) == -1)
                return -1;
            }

        else if (strcmp(cmd, "pop") == 0)
            {
            int a = 0;

            ass_massa.code[ass_massa.sizee++] = POP;
            fgets(cmd, 50, in);
            if (StrAnalysisPop(&ass_massa, cmd) == -1)
                return -1;
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

        else if (strcmp(cmd, "call") == 0)
            {
            char a[20] = "";
            ass_massa.code[ass_massa.sizee++] = CALL;
            fscanf(in, "%s", &a);
            if (strchr(a, ';') > 0)
                ass_massa.code[ass_massa.sizee++] = checkMark(a, true, &lm, ass_massa, &postCompil);
            else
                {
                printf("ERROR_MAKR_DONT_SEAK");
                return -1;
                }
            }

        else if (strcmp(cmd, "ret") == 0)
            {
            ass_massa.code[ass_massa.sizee++] = RET;
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

    signature head = { SIGNATURE, VERSION_COM, ass_massa.sizee};

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

    ass_massa->capasity = MIN_CAPASITYY;
    ass_massa->sizee = 0;
    }

int checkMark(char* cmd, bool inComand, listMarks* lm, ass_mas ass_massa, listMarks* postCompil)
    {
    if (inComand == true)
        {
        for( int i = 0; i < lm->index; i++)
            {
            if ((strcmp(lm->listt[i].name, cmd) == 0) && (lm->listt[i].index != -1))
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

                break;
                }
            }
        }
    return 0;
    }

bool BracketAnalysis(char* str, int* status)
    {
    char* ptr1 = strchr(str, '[');
    char* ptr2 = strchr(str, ']');
    if (ptr1 != NULL && ptr2 != NULL && ptr1 < ptr2)
        {
        strncpy(str, ptr1 + 1, ptr2 - ptr1 - 1);
        str[ptr2 - ptr1 - 1] = '\0';

        *status += BRACKET;
        return true;
        }
    return false;
    }

bool RegAnalysis(char* str, int* reg)
    {
    bool out = true;
    sscanf(str, "%s", str);
    if (strcmp(str, "ax") == 0)      *reg = AX;
    else if (strcmp(str, "bx") == 0) *reg = BX;
    else if (strcmp(str, "cx") == 0) *reg = CX;
    else if (strcmp(str, "dx") == 0) *reg = DX;
    else if (strcmp(str, "ex") == 0) *reg = EX;
    else if (strcmp(str, "fx") == 0) *reg = FX;
    else if (strcmp(str, "gx") == 0) *reg = GX;
    else if (strcmp(str, "hx") == 0) *reg = HX;
    else out = false;
    return out;
    }


bool NumberAnalysis(char* str, int* num)
    {
    if (sscanf(str, "%d", num)) return true;
    else return false;
    }


int ArgAnalysis(char* str, int* value)
    {
    if (RegAnalysis(str, value)) return REG;
    else if (NumberAnalysis(str, value)) return NUM;
    else return -1;
    }


int PlusAnalysis(char* str, int* status, int* reg, int* num)
    {
    char* plus_ptr = strchr(str, '+');
    if (plus_ptr)
        {
        *plus_ptr = '\0';
        char* str1 = str;
        char* str2 = plus_ptr + 1;

        int valueInStr1 = 0;
        int valueInStr2 = 0;

        int type1 = ArgAnalysis(str1, &valueInStr1);
        if (type1 == -1) return -1;
        int type2 = ArgAnalysis(str2, &valueInStr2);
        if (type2 == -1) return -1;

        if (type1 == REG && type2 == REG) return -1;
        else if (type1 == REG && type2 == NUM)
            {
            *status += REG_NUM;
            *reg = valueInStr1;
            *num = valueInStr2;
            }
        else if (type1 == NUM && type2 == REG)
            {
            *status += REG_NUM;
            *reg = valueInStr2;
            *num = valueInStr1;
            }
        else if (type1 == NUM && type2 == NUM)
            {
            *status += NUM;
            *num = valueInStr1 + valueInStr2;
            }
        }

    else
        {
        int value = 0;
        int type = ArgAnalysis(str, &value);
        if (type == REG)
            {
            *status +=REG;
            *reg = value;
            }
        else if (type == NUM)
            {
            *status += NUM;
            *num = value;
            }
        else
            {
            return -1;
            }
        }
    }


int StrAnalysisPush(ass_mas* ass_massa, char* cmd)
    {
    int reg = 0;
    int num = 0;
    int status = 0;

    BracketAnalysis(cmd, &status);
    if (PlusAnalysis(cmd, &status, &reg, &num) == -1)
        {
        printf("ERROR_ARG_PUSH");
        return -1;
        }

    ass_massa->code[ass_massa->sizee++] = status;
    if (status == BRACKET) return -1;
    if (status & REG)
        ass_massa->code[ass_massa->sizee++] = reg;
    if (status & NUM)
        ass_massa->code[ass_massa->sizee++] = num;

    return 0;
    }


int StrAnalysisPop(ass_mas* ass_massa, char* cmd)
    {
    int reg = 0;
    int num = 0;
    int status = 0;

    BracketAnalysis(cmd, &status);
    if (PlusAnalysis(cmd, &status, &reg, &num) == -1)
        {
        printf("ERROR_ARG_PUSH");
        return -1;
        }

    ass_massa->code[ass_massa->sizee++] = status;
    if (status == BRACKET) return -1;
    if (status & BRACKET)
        {
        if (status & REG)
            ass_massa->code[ass_massa->sizee++] = reg;
        if (status & NUM)
            ass_massa->code[ass_massa->sizee++] = num;
        }
    else if (status == REG)
        ass_massa->code[ass_massa->sizee++] = reg;
    else return -1;

    return 0;
    }

