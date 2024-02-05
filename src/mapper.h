#pragma once
#include "base.h"

constexpr int MEMORY_SIZE = 0x10000;

class Mapper {
    byte *memory;

public:
    Mapper();
    ~Mapper();

    byte &operator[] (word address);
};
