#include <stdio.h>
#include "ir.h"

#define NUM_CHARS = 256
static op_t charToOp[NUM_CHARS];

#define CHAR_TO_OP(character) (charToOp[(int) character])
#define SET_CHAR_OP(character, op) (charToOp[(int) character] = op)

ir_t initialize_parser() {
    for (char c = 0; c < NUM_CHARS; c++) 
        CHAR_TO_IR[c] = -1; // Use "-1" as a comment char.
    SET_CHAR_OP('>', rshift);
    SET_CHAR_OP('<', lshift);
    SET_CHAR_OP('+', inc);
    SET_CHAR_OP('-', dec);
    SET_CHAR_OP(',', input);
    SET_CHAR_OP('.', ouput);
    SET_CHAR_OP('[', bloop);
    SET_CHAR_OP(']', eloop);
}

static int c = '\0'; // One character buffer

ir_t next_ir(FILE *stream) {    
    ir_t ir;
    int count = 1;

    // Fetch next char to process
    while (CHAR_TO_OP(c) < 0 && c != EOF) 
        c = getc(stream);
    if (c == EOF) 
        return NULL_IR;  

    op_t op = CHAR_TO_OP(c);
    SET_OP(ir, op);

    // Condense all like ops in the future
    while (count < MAX_COUNT && c != EOF && CHAR_TO_OP(c) == op) {
        count++;
        do {
            c = getc(stream); 
        } while(CHAR_TO_OP(c) < 0 && c != EOF);
    }

    SET_COUNT(ir, count);
    
    return ir;
}