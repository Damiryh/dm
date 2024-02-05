#pragma once
#include "mapper.h"

class Processor {
    Mapper &m;
    word cp, sp, idx;
    byte a, b;

    byte read8();
    word read16();

public:
    bool running;

    Processor(Mapper &mapper);
    void tick();
};
