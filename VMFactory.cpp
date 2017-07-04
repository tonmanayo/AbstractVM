//
// Created by Tony MACK on 2017/07/03.
//

#include "VMFactory.hpp"
#include "Operands.hpp"

VMFactory::VMFactory() {
    createOpp[int8] = &VMFactory::createInt8;
    createOpp[int16] = &VMFactory::createInt16;
    createOpp[int32] = &VMFactory::createInt32;
    createOpp[Float] = &VMFactory::createFloat;
    createOpp[Double] = &VMFactory::createDouble;
}

//VMFactory::VMFactory(const VMFactory &) {}
//const VMFactory &VMFactory::operator=(const VMFactory &) {}

IOperand const *VMFactory::createOperand(eOperandType type, std::string const &value) const {
    IOperand const *(VMFactory::*fCreate)(std::string const &value) const;
    fCreate = createOpp.at(type);
    return ((*this.*fCreate)(value));
}

IOperand const *VMFactory::createInt8(std::string const &value) const {
    return (new Operands<char>(value, int8, 0, this));
}

IOperand const *VMFactory::createInt16(std::string const &value) const {
    return (new Operands<char>(value, int16, 0, this));
}

IOperand const *VMFactory::createInt32(std::string const &value) const {
    return (new Operands<char>(value, int32, 0, this));
}

IOperand const *VMFactory::createFloat(std::string const &value) const {
    return (new Operands<char>(value, Float, 7, this));
}

IOperand const *VMFactory::createDouble(std::string const &value) const {
    return (new Operands<char>(value, Double, 14, this));
}

VMFactory::~VMFactory() {}
