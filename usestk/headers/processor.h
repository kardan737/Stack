enum comand
    {
    PUSH = 1,
    POP  = 2,
    ADD  = 3,
    SUB  = 4,
    MUL  = 5,
    DIV  = 6,
    SQRT = 7,
    SIN  = 8,
    COS  = 9,
    IN   = 10,
    OUT  = 11,
    DUMP = 12,
    HLT  = 13,
    JA   = 14,
    JAE  = 15,
    JB   = 16,
    JBE  = 17,
    JE   = 18,
    JNE  = 19,
    JMP  = 20,
    CALL = 21,
    RET  = 22,
    };

enum registers
    {
    AX = 1,
    BX = 2,
    CX = 3,
    DX = 4,
    EX = 5,
    FX = 6,
    GX = 7,
    HX = 8,
    };

enum value
    {
    REG             = 1,
    NUM             = 2,
    REG_NUM         = 3,
    BRACKET         = 4,
    REG_BRACKET     = 5,
    NUM_BRACKET     = 6,
    REG_NUM_BRACKET = 7,
    };

const size_t MIN_CAPASITYY = 15000;
const long long SIGNATURE = 0x584F4C444544;
const size_t VERSION_COM = 2;
const size_t LENGTH_ARRAY_MASKS = 20;

struct ass_mas
    {
    int* code;
    size_t capasity;
    int sizee;
    };

struct signature
    {
    long long sig;
    size_t versComand;
    int sizee;
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
