#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/stack.h"
#include "../headers/verify.h"

#include "../headers/processor.h"

struct mask
    {
    char name;
    int value;
    };

struct my_spu
    {

    int* registers;
    size_t ip;
    int* assm;
    my_stack* stk;
    };

int SpuCtor(my_spu* spu, signature* head, FILE* in);

int main(int argc, char* argv[])
    {

    my_stack stk = {};
    StackCtor(&stk, MIN_CAPASITYY);

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
        printf("command: %d >>> %d\n", cmd, spu.ip - 1);
        switch(cmd)
            {
            case PUSH:
                {
                int arg = spu.assm[spu.ip++];
                StackPush(&stk, arg);
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
                scanf("enter a number: %d", &a);
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
        }
    }

int SpuCtor(my_spu* spu, signature* head, FILE* in)
    {
    spu->ip = 0;

    fread(&head->sig, sizeof(long long), 1, in);
//    if (head->sig != QQQQ)
//        {
//        printf("signa");
//        return -1;
//        }

    fread(&head->versComand, sizeof(size_t), 1, in);
//    if (head->versComand != QQQQ)
//        {
//        printf("vers");
//        return -1;
//        }

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
