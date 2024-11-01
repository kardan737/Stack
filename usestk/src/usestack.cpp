#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/stack.h"
#include "../headers/verify.h"

#include "../headers/processor.h"

struct mask
    {                                               // сделать вызов функции из нескольких мест
    char name;                                            //если просто метка то одна а если в колле то можно и несколько
    int value;
    };

struct my_spu
    {
    int* assm;
    size_t ip;
    int registers[8];
    int ram[100];
    my_stack* stk;

    };

int SpuCtor(my_spu* spu, signature* head, FILE* in);
int SpuDump(my_spu* spu, int cmd);

int main(int argc, char* argv[])
    {

    my_stack stk = {};
    StackCtor(&stk, MIN_CAPASITYY);

    my_stack stkFunc = {};
    StackCtor(&stkFunc, MIN_CAPASITYY);

    const char* instruction = "";

    if (argc != 2)
        instruction = "../file/compil.txt";
    else
        instruction = argv[1];

    FILE *in = fopen(instruction, "rb");
    if (!in)
        {
        printf("OPENING_ERROR");
        return -1;
        }

    my_spu spu = {};

    signature head = {};
    SpuCtor(&spu, &head, in);

    bool runWhile = true;
    while(runWhile)
        {
        int cmd = spu.assm[spu.ip++];


        switch(cmd)
            {
            case PUSH:
                {
                int status = spu.assm[spu.ip++];
                int value = 0;
                switch(status)
                    {
                    case REG:
                        value = spu.registers[spu.assm[spu.ip++] - 1];
                        break;

                    case NUM:
                        value = spu.assm[spu.ip++];
                        break;

                    case REG_NUM:
                        value += spu.registers[spu.assm[spu.ip++] - 1];
                        value += spu.assm[spu.ip++];
                        break;

                    case REG_BRACKET:
                        value = spu.ram[spu.registers[spu.assm[spu.ip++] - 1]];
                        break;

                    case NUM_BRACKET:
                        value = spu.ram[spu.assm[spu.ip++]];
                        break;

                    case REG_NUM_BRACKET:
                        value += spu.registers[spu.assm[spu.ip++] - 1];
                        value += spu.assm[spu.ip++];
                        value =  spu.ram[value];
                        break;

                    default:
                        printf("SIN_ASM_ERROR");
                        runWhile = false;
                        break;

                    }

                StackPush(&stk, value);
                break;
                }

            case POP:
                {
                int a = StackPop(&stk);
                int status = spu.assm[spu.ip++]; // „итаем следующий байт команды, определ€ющий тип POP
                int* dest = nullptr;           // ”казатель на место назначени€ записи

                switch(status)
                    {
                    case REG:
                        dest = &spu.registers[spu.assm[spu.ip++] - 1];
                        break;

                    case REG_BRACKET:
                        dest = &spu.ram[spu.registers[spu.assm[spu.ip++] - 1]];
                        break;

                    case NUM_BRACKET:
                        dest = &spu.ram[spu.assm[spu.ip++]];
                        break;

                    case REG_NUM_BRACKET:
                        {
                        int reg_val = spu.registers[spu.assm[spu.ip++] - 1];
                        int offset = spu.assm[spu.ip++];
                        dest = &spu.ram[reg_val + offset];
                        break;
                        }

                    default:
                        printf("SIN_ASM_ERROR");
                        runWhile = false;
                        break;
                    }

                if (dest)
                    *dest = a;

                break;
                }

            case ADD:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                StackPush(&stk, a + b);
                break;
                }

            case SUB:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                StackPush(&stk, b - a);
                break;
                }

            case MUL:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                StackPush(&stk, a * b);
                break;
                }

            case DIV:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                StackPush(&stk, b / a);
                break;
                }

            case SQRT:
                {
                int a = StackPop(&stk);
                StackPush(&stk, sqrt(a));
                break;
                }

            case SIN:
                {
                int a = StackPop(&stk);
                StackPush(&stk, sin(a));
                break;
                }

            case COS:
                {
                int a = StackPop(&stk);
                StackPush(&stk, cos(a));
                break;
                }

            case IN:
                {
                int a = 0;
                scanf("%d", &a);
                StackPush(&stk, a);
                break;
                }

        /*case DUMP:
            {
            StackDump(&stk);
            }*/
            case JA:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                if (b > a)
                    {
                    spu.ip = spu.assm[spu.ip];
                    break;
                    }
                ++spu.ip;
                break;
                }

            case JAE:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                if (b >= a)
                    {
                    spu.ip = spu.assm[spu.ip];
                    break;
                    }
                ++spu.ip;
                break;
                }

            case JB:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                if (b < a)
                    {
                    spu.ip = spu.assm[spu.ip];
                    break;
                    }
                ++spu.ip;
                break;
                }

            case JBE:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                if (b <= a)
                    {
                    spu.ip = spu.assm[spu.ip];
                    break;
                    }
                ++spu.ip;
                break;
                }

            case JE:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                if (b == a)
                    {
                    spu.ip = spu.assm[spu.ip];
                    break;
                    }
                ++spu.ip;
                break;
                }

            case JNE:
                {
                int a = StackPop(&stk);
                int b = StackPop(&stk);
                if (b != a)
                    {
                    spu.ip = spu.assm[spu.ip];
                    break;
                    }
                ++spu.ip;
                break;
                }

            case JMP:
                {
                spu.ip = spu.assm[spu.ip];
                break;
                }

            case CALL:
                {
                StackPush(&stkFunc, spu.ip + 1);
                spu.ip = spu.assm[spu.ip];
                break;
                }

            case RET:
                {
                spu.ip = StackPop(&stkFunc);
                break;
                }

            case OUT:
                printf("result = %d\n", StackPop(&stk));
                break;

            case HLT:
                runWhile = false;
                printf("end prog\n");
                break;

            default:
                printf("SIN_TERROR\n");
                runWhile = false;
                break;

            }
        SpuDump(&spu, cmd);
        }

    StackDtor(&stk);
    StackDtor(&stkFunc);
    }

int SpuCtor(my_spu* spu, signature* head, FILE* in)
    {
    spu->ip = 0;

    fread(&head->sig, sizeof(long long), 1, in);
    if (head->sig != SIGNATURE)
        {
        printf("signa_DONT_SEAK");
        return -1;
        }

    fread(&head->versComand, sizeof(size_t), 1, in);
    if (head->versComand != VERSION_COM)
        {
        printf("vers_com");
        return -1;
        }

    fread(&head->sizee, sizeof(size_t), 1, in);

    spu->assm = (int*)calloc(head->sizee, sizeof(int));
    if (spu->assm == nullptr)
        {
        printf("MEMORY_ALLOCATION_ERROR");
        return -1;
        }

    int result = fread(spu->assm, sizeof(int), head->sizee, in);
    if (result != head->sizee)
        {
        printf("READING_ASM_ERROR");
        return -1;
        }

    }

int SpuDump(my_spu* spu, int cmd)
    {
    printf("registers:  ");
    for (int i = 0; i < 8; i++)
        {
        printf("%d ", spu->registers[i]);
        }

    printf("\n\n");

    printf("stack:  ");
//    for (int i = 0; i < spu->stk->sizee; i++)
//        {
//        printf("%d", spu->stk->addr[i]);
//        }

    printf("\n\n");

    printf("command: %d >>> ip: %d\n", cmd, spu->ip - 1);

    printf("\n\n");
    return 0;
    }


//int SpuDtor(...)
