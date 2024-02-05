#include "mapper.h"


Mapper::Mapper() {
    memory = new byte[MEMORY_SIZE];
}


Mapper::~Mapper() {
    delete[] memory;
}


byte &Mapper::operator[] (word address) {
    return memory[address];
}
