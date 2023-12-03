#include <iostream>
#include "libs/include/processor.h"


int main()
{
    processor cpu = processor();

    std::cout << 0x1234 << std::endl;
    std::cout << (0x1234 & 0xFF) << std::endl;
    std::cout << ((0x1234 >> 8) & 0xFF) << std::endl;

    std::cout << "AX : " << (int)cpu.getAXValue() << std::endl;
    std::cout << "AL : " << (int)cpu.getALValue() << std::endl;
    std::cout << "AH : " << (int)cpu.getAHValue() << std::endl;
    std::cout << "\n" << std::endl;

    cpu.process(Instructions::MOV, { "AX", "0x1234" });

    std::cout << "AX : " << (int)cpu.getAXValue() << std::endl;
    std::cout << "AL : " << (int)cpu.getALValue() << std::endl;
    std::cout << "AH : " << (int)cpu.getAHValue() << std::endl;
    std::cout << "\n" << std::endl;

    return 0;
}
