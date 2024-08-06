#include "mapper.h"
#include "processor.h"
#include <iostream>

int main(int argc, char **argv) {
    Mapper mapper;
    Processor processor(mapper);

    std::string filename("samples/test.bin");
    if (!mapper.load(filename)) {
        std::cout << "dm: can't open file '" << filename << "'" << std::endl;
        return 1;
    }

    while (processor.running) {
        processor.tick();
    }
    return 0;
}
