//
// Created by Tony MACK on 2017/07/03.
//

#ifndef ABSTRACTVM_VMFACTORY_HPP
#define ABSTRACTVM_VMFACTORY_HPP

#include <cstdlib>
#include <map>
#include "IOperand.hpp"

class VMFactory {

private:
    IOperand const *createInt8( std::string const &value ) const;
    IOperand const *createInt16( std::string const &value ) const;
    IOperand const *createInt32( std::string const &value ) const;
    IOperand const *createFloat( std::string const &value ) const;
    IOperand const *createDouble( std::string const &value ) const;

    std::map<eOperandType, IOperand const*(VMFactory::*)(std::string const &value) const> createOpp;
public:
    VMFactory();
    VMFactory(const VMFactory&);
    VMFactory& operator=(const VMFactory&);
    IOperand const *createOperand(eOperandType type, std::string const &value) const;
    ~VMFactory();
};


#endif //ABSTRACTVM_VMFACTORY_HPP
