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
    OUT  = 10,
    DUMP = 11,
    HLT  = 12,
    JA   = 13,
    JAE  = 14,
    JB   = 15,
    JBE  = 16,
    JE   = 17,
    JNE  = 18,
    JMP  = 19,
    };

const size_t MIN_CAPASITYY = 150000;
//const size_t SIGNATURE = 4;
//const size_t VERSION_COM = 2;
const size_t LENGTH_ARRAY_MASKS = 20;

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

struct masks
    {
    char name[50];
    int index;
    };

struct listMarks
    {
    masks listt[LENGTH_ARRAY_MASKS];
    size_t index;
    };
