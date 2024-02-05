#include "processor.h"

#define check(opcode, mask) if ((op & mask) == opcode)


Processor::Processor(Mapper &mapper): m(mapper) {
    running = true;
    cp = 0x0000;
    sp = 0xffff;
}


void Processor::tick() {
    byte op = read8();

    check(0xff, 0xff) {
        running = false;
    }
}


byte Processor::read8() {
    return m[cp++];
}


word Processor::read16() {
    word value = (m[cp+1] << 8) | m[cp];
    cp += 2;
    return value;
}
