#ifndef STACK_H
#define STACK_H


struct my_stack
    {
    //long long left_struck_chica;    and stack

    int* addr;
    size_t  sizee;
    size_t  capasity;
    bool error;  ///!!!!

    //long long right_struct_chika;   and stack

    };

const int min_capasity = 16;


bool StackCtor(my_stack* stk, int min_capasity);
bool StackPush(my_stack* stk, int new_element);
int StackPop(my_stack* stk);
bool ExtendMemory(my_stack* stk);
bool StackCut(my_stack* stk);
bool StackDtor(my_stack* stk);

#endif
