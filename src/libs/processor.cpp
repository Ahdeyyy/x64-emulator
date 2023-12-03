#include "./include/processor.h"
#include <iostream>

void processor::move(uint16_t& dest, uint16_t& src) {
    dest = src;
}

void processor::move(uint8_t& dest, uint8_t& src) {
    dest = src;

}

void processor::move(uint16_t& dest, uint8_t& src) {
    dest = src;

}

uint16_t processor::getAXValue() {
    return AX;
}
uint8_t processor::getALValue() {
    return AL;
}

uint8_t processor::getAHValue() {
    return AH;
}

void processor::updateLower8() {
    AL = AX & 0xFF; // 8 bit Accumulator Register
    AH = (AX >> 8) & 0xFF; // 8 bit Accumulator Register
    BL = BX & 0xFF; // 8 bit Base Register
    BH = (BX >> 8) & 0xFF; // 8 bit Base Register
    CL = CX & 0xFF; // 8 bit Count Register
    CH = (CX >> 8) & 0xFF; // 8 bit Count Register
    DL = DX & 0xFF; // 8 bit Data Register
    DH = (DX >> 8) & 0xFF; // 8 bit Data Register
}

void processor::process(Instructions opcode, std::vector<std::string> operands) {

    switch (opcode) {
    case Instructions::MOV:
        /* code */
        if (operands.size() != 2) {
            std::cout << "Invalid number of operands for MOV instruction, got " << operands.size() << std::endl;
            break;
        }

        if (operands[0] == "AX") {
            if (isRegister(operands[1])) {
                move(AX, *getRegister(operands[1]));
            }

            else if (isRegister8(operands[1])) {
                move(AX, *getRegister8(operands[1]));
            }
            else {
                if (operands[1].substr(0, 2) == "0x") {
                    AX = std::stoi(operands[1], nullptr, 16);
                }
                else if (std::isdigit(operands[1][0])) {
                    AX = std::stoi(operands[1], nullptr, 10);
                }
                else {
                    std::cout << "Invalid operand for MOV instruction: " << operands[1] << std::endl;
                }

            }

        }

        break;

    default:
        std::cout << "Invalid opcode: " << opcode << std::endl;
        break;
    }

    updateLower8();
}

bool processor::isRegister(std::string operand) {
    for (auto reg : registers) {
        if (operand == reg) {
            return true;
        }
    }
    return false;
}

bool processor::isRegister8(std::string operand) {
    for (auto reg : registers8) {
        if (operand == reg) {
            return true;
        }
    }
    return false;
}

uint16_t* processor::getRegister(std::string operand) {
    if (isRegister(operand)) {
        if (operand == "AX") {
            return &AX;
        }
        else if (operand == "BX") {
            return &BX;
        }
        else if (operand == "CX") {
            return &CX;
        }
        else if (operand == "DX") {
            return &DX;
        }
        else if (operand == "SP") {
            return &SP;
        }
        else if (operand == "BP") {
            return &BP;
        }
        else if (operand == "SI") {
            return &SI;
        }
        else if (operand == "DI") {
            return &DI;
        }
    }

    return nullptr;

}

uint8_t* processor::getRegister8(std::string operand) {
    if (isRegister8(operand)) {
        if (operand == "AL") {
            return &AL;
        }
        else if (operand == "AH") {
            return &AH;
        }
        else if (operand == "BL") {
            return &BL;
        }
        else if (operand == "BH") {
            return &BH;
        }
        else if (operand == "CL") {
            return &CL;
        }
        else if (operand == "CH") {
            return &CH;
        }
        else if (operand == "DL") {
            return &DL;
        }
        else if (operand == "DH") {
            return &DH;
        }
    }

    return nullptr;

}