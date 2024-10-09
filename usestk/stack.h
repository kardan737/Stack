#ifndef STACK_H
#define STACK_H


struct my_stack
    {
    long long left_struct_chica;    //and stack

    int* addr;
    size_t  sizee;
    size_t  capasity;
    bool error;  ///!!!!

    long long right_struct_chica;   //and stack

    };

const int MIN_CAPASITY = 16;
const long long COCK = 0XDEDBABA52525252;

bool StackCtor(my_stack* stk, int MIN_CAPASITY);
bool StackPush(my_stack* stk, int new_element);
int StackPop(my_stack* stk);
bool ExtendMemory(my_stack* stk);
bool StackCut(my_stack* stk);
bool StackDtor(my_stack* stk);

#endif
