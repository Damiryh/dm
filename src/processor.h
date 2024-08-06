#pragma once
#include "mapper.h"

class Processor {
    Mapper &m;
    word cp, sp, idx;
    byte a, b;
    bool zero, carry;

    byte read8();
    word read16();

    void add(bool carryIn);
    void sub(bool borrowIn);
    void jmp(bool cond, word addr);
    void call(word addr);

    void push8(byte value);
    void push16(word value);

    byte pop8();
    word pop16();

public:
    bool running;

    Processor(Mapper &mapper);
    void tick();
};
