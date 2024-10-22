enum comand         // header
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
    OUT  = 10,
    DUMP = 11,
    HLT  = 12,
    JA   = 13
    JAE  = 14
    JB   = 15
    JBE  = 16
    JNE  = 17
    JMP  = 18
    };

//const size_t MIN_LENGTH = 15;
//const size_t SIGNATURE = 4;
//const size_t VERSION_COM = 2;

struct ass_mas
    {
    int* code;
    size_t capacity;
    size_t sizee;
    };

struct signature
    {
    long long sig;
    size_t versComand;
    size_t sizee;
    };
