#include "mapper.h"
#include "processor.h"

int main(int argc, char **argv) {
    Mapper mapper;
    Processor processor(mapper);

    while (processor.running) {
        processor.tick();
    }
    return 0;
}
