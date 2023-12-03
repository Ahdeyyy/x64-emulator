#pragma once

#include <vector>
#include <string>
#include <stdint.h>

enum Instructions {
    MOV,
};

class processor {
private:

    std::vector<std::string> registers = { "AX", "BX", "CX", "DX", "SP", "BP", "SI", "DI", };
    std::vector<std::string> registers8 = { "AL", "AH", "BL", "BH", "CL", "CH", "DL", "DH", };


    uint16_t memory[65536]; // 64Kb of memory
    uint16_t stack[65536]; // 64Kb of stack

    // 16 bit Registers
    uint16_t AX = 0x0000; // 16 bit Accumulator Register
    uint16_t BX = 0x0000; // 16 bit Base Register
    uint16_t CX = 0x0000; // 16 bit Count Register
    uint16_t DX = 0x0000; // 16 bit Data Register
    uint16_t SP = 0xFFFF; // 16 bit Stack Pointer
    uint16_t BP = 0x0000; // 16 bit Base Pointer
    uint16_t SI = 0x0000; // 16 bit Source Index
    uint16_t DI = 0x0000; // 16 bit Destination Index

    // flags
    bool CF = false; // Carry Flag
    bool PF = false; // Parity Flag
    bool AF = false; // Auxiliary Flag
    bool ZF = false; // Zero Flag
    bool SF = false; // Sign Flag
    bool OF = false; // Overflow Flag
    bool DF = false; // Direction Flag
    bool IF = false; // Interrupt Flag
    bool TF = false; // Trap Flag

    // 8 bit Registers
    uint8_t AL = AX & 0xFF; // 8 bit Accumulator Register
    uint8_t AH = (AX >> 8) & 0xFF; // 8 bit Accumulator Register
    uint8_t BL = BX & 0xFF; // 8 bit Base Register
    uint8_t BH = (BX >> 8) & 0xFF; // 8 bit Base Register
    uint8_t CL = CX & 0xFF; // 8 bit Count Register
    uint8_t CH = (CX >> 8) & 0xFF; // 8 bit Count Register
    uint8_t DL = DX & 0xFF; // 8 bit Data Register
    uint8_t DH = (DX >> 8) & 0xFF; // 8 bit Data Register




public:
    processor() = default;
    ~processor() = default;


    // 16 bits move
    void move(uint16_t& dest, uint16_t& src);
    // 8 bits move
    void move(uint8_t& dest, uint8_t& src);
    // 8 bits to 16 bits move
    void move(uint16_t& dest, uint8_t& src);

    // update lower 8 bits of 16 bit register
    void updateLower8();


    void process(Instructions opcode, std::vector<std::string> operands);


    uint16_t getAXValue();
    uint8_t getALValue();
    uint8_t getAHValue();

    bool isRegister(std::string operand);
    bool isRegister8(std::string operand);
    uint16_t* getRegister(std::string operand);
    uint8_t* getRegister8(std::string operand);

};