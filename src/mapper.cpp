#include "mapper.h"
#include <fstream>


Mapper::Mapper()
{
    memory = new byte[MEMORY_SIZE];
}


Mapper::~Mapper()
{
    delete[] memory;
}


byte &Mapper::operator[] (word address)
{
    return memory[address];
}


bool Mapper::load(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    file.read((char*)memory, MEMORY_SIZE);
    return true;
}
