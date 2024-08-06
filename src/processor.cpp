#include "processor.h"
#include "opcodes.h"
#include <stdio.h>

#define check(opcode, mask) if ((op & mask) == opcode)


Processor::Processor(Mapper &mapper): m(mapper) {
    running = true;
    cp = 0x0000;
    sp = 0xffff;
}


void Processor::tick() {
    if (!running) return;
    #ifdef DEBUG
    printf("CP=%04x SP=%04x IDX=%04x A=%02x B=%02x Z=%d C=%d\n",
        cp, sp, idx, a, b, zero, carry);
    #endif


    byte op = read8();
    byte temp = 0x00;

    check(OP_HLT, 0xff) { running = false; } else
    check(OP_LD | IMM, 0xff) { a = read8(); } else
    check(OP_LD | DIR, 0xff) { a = m[read16()]; } else
    check(OP_LD | IDX, 0xff) { a = m[idx]; } else
    check(OP_ST | DIR, 0xff) { m[read16()] = a; } else
    check(OP_ST | DIR, 0xff) { m[idx] = a; } else
    check(OP_SWP, 0xff) { temp = a; a = b; b = temp; } else
    check(OP_ADD, 0xff) { add(false); } else
    check(OP_ADC, 0xff) { add(carry); } else
    check(OP_SUB, 0xff) { sub(false); } else
    check(OP_SBB, 0xff) { sub(carry); } else
    check(OP_AND, 0xff) { a = a & b; } else
    check(OP_OR,  0xff) { a = a | b; } else
    check(OP_NOT, 0xff) { a = ~a; } else
    check(OP_TST, 0xff) { temp = a & b; zero = (a == 0); } else
    check(OP_CMP, 0xff) { zero = (a == b); carry = (a > b); } else
    check(OP_LDI, 0xff) { idx = read16(); } else
    check(OP_JMP, 0xff) { jmp(true, read16()); } else
    check(OP_JZ,  0xff) { jmp(zero, read16()); } else
    check(OP_JC,  0xff) { jmp(carry, read16()); } else
    check(OP_JNZ, 0xff) { jmp(!zero, read16()); } else
    check(OP_JNC, 0xff) { jmp(!carry, read16()); } else
    check(OP_CALL, 0xff) { call(read16()); } else
    check(OP_RET, 0xff) { cp = pop16(); }
}


byte Processor::read8() {
    return m[cp++];
}


word Processor::read16() {
    word value = (m[cp+1] << 8) | m[cp];
    cp += 2;
    return value;
}


void Processor::add(bool carryIn)
{
    int temp = a + b + carryIn;
    carry = temp > 0xff;
    a = temp & 0xff;
}


void Processor::sub(bool borrowIn)
{
    int temp = a - b - borrowIn;
    carry = temp < 0x00;
    a = temp & 0xff;
}


void Processor::jmp(bool cond, word addr)
{
    if (cond) { cp = addr; }
}


void Processor::call(word addr)
{
    push16(cp);
    cp = addr;
}


void Processor::push8(byte value)
{
    m[sp] = value;
    sp++;
}


void Processor::push16(word value)
{
    m[sp] = value & 0xff;
    m[sp + 1] = (value >> 8);
    sp += 2;
}


byte Processor::pop8()
{
    sp--;
    return m[sp];
}


word Processor::pop16()
{
    sp -= 2;
    return (m[sp + 1] << 8) | m[sp];
}
