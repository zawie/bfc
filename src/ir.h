typedef unsigned int ir_t;

#define NULL_IR = 0xffffffff
#define MAX_COUNT = 0xffffffff >> 3;

enum op_t {
    rshift  = 0,    // >
    lshift  = 1,    // <
    inc     = 2,    // +
    dec     = 3,    // -
    input   = 4,    // ,
    output  = 5,    // .
    bloop   = 6,    // [
    eloop   = 7     // ]
}

#define GET_OP (ir)     (ir &   0b111)
#define SET_OP (ir, op) (ir & (~0b111 ^ op))

#define GET_COUNT (ir)        (ir >> 3)
#define SET_COUNT (ir, count) (ir & (0b111 ^ (count << 3)))



