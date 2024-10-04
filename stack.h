struct my_stack
    {
    int* addr;
    int  sizee;
    int  capasity;
    //int  error;

    };

const int min_capasity = 16;


bool StackCtor(my_stack* stk, int min_capasity);
bool StackPush(my_stack* stk, int new_element);
int StackPop(my_stack* stk);
bool ExtendMemory(my_stack* stk);
bool StackCut(my_stack* stk);
bool StackDtor(my_stack* stk);


