//
// Created by Tony MACK on 2017/06/28.
//

#ifndef ABSTRACTVM_OPERANDS_HPP
#define ABSTRACTVM_OPERANDS_HPP

#include "IOperand.hpp"

template <typename T>
class IOperands : public IOperand{
public:
    virtual int getPrecision( void ) {

    }

    virtual eOperandType getType( void ) {
        return _type;
    }

    IOperand const *operator+(IOperand const &rhs){
       eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        if (_type < Float){

        }
    }

    virtual IOperand const *operator-( IOperand const &rhs ) {

    }

    virtual IOperand const *operator*( IOperand const &rhs ) {

    }

    virtual IOperand const *operator/( IOperand const &rhs ) {

    }

    virtual IOperand const *operator%( IOperand const & hs ) {

    }

    virtual std::string const &toString( void ) {
        return _string;
    }
private:
    T               _value;
    eOperandType    _type;
    std::string     _string;
};

#endif //ABSTRACTVM_OPERANDS_HPP
