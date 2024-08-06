#pragma once
#include "base.h"
#include <string>

constexpr int MEMORY_SIZE = 0x10000;

class Mapper {
    byte *memory;

public:
    Mapper();
    ~Mapper();

    bool load(std::string filename);
    byte &operator[] (word address);
};
