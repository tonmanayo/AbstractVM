//
// Created by Tony MACK on 2017/06/28.
//

#ifndef ABSTRACTVM_OPERANDS_HPP
#define ABSTRACTVM_OPERANDS_HPP

#include "IOperand.hpp"
#include "VMFactory.hpp"
#include <limits.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <cfloat>


template <typename T>
class Operands : public IOperand{
public:

    Operands();
    Operands(const Operands& rhs);
    const Operands&operator=(const Operands&);

    template <typename C>
    bool checkTypeOverflow(C val, eOperandType type) const{
        switch (type) {
            case int8:   return (val > 127 || val < -128);
            case int16:  return (val > 32767 || val < -32768);
            case int32:  return (val > 2147483647 || val < -2147483648);
            case Float:  return (val > FLT_MAX || val < FLT_MIN);
            case Double: return (val > DBL_MAX || val < DBL_MIN);
        }
        return true;
    }

    int getPrecision(void) const{
        return _precision;
    }

    eOperandType getType(void) const{
        return _type;
    }

    Operands(std::string const &val, eOperandType type, int precision, const VMFactory *factory): _type(type), _precision(precision), _factory(factory){
        if (type <= Float)
        {
            long double	nVal = std::stold(val);
            if (checkTypeOverflow<long double>(nVal, type))
                throw std::runtime_error("Error creating value!");
            _value = static_cast<T>(nVal);
            std::stringstream c_out;
            c_out << std::setprecision(precision) << nVal;
            _string = c_out.str();
        } else {
            throw std::runtime_error("Type Error!");
        }
    }

    IOperand const *operator+(IOperand const &rhs) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type <= Float)
        {
            long double nVal = std::stoll(_string) + std::stoll(rhs.toString());
            if (checkTypeOverflow<long double>(nVal, type))
                throw std::runtime_error("Overflow of value !");
            ss << nVal;
        } else
            throw std::runtime_error("Type Error!");

        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator-( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type <= Float)
        {
            long double nVal = std::stoll(_string) + std::stoll(rhs.toString());
            if (checkTypeOverflow<long double>(nVal, type))
                throw std::runtime_error("Overflow of value !");
            ss << nVal;
        } else
            throw std::runtime_error("Type Error!");

        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator*( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type <= Float)
        {
            long double nVal = std::stoll(_string) - std::stoll(rhs.toString());
            if (checkTypeOverflow<long double>(nVal, type))
                throw std::runtime_error("Overflow of value !");
            ss << nVal;
        } else
            throw std::runtime_error("Type Error!");

        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator/( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type <= Float)
        {
            long double nVal = std::stoll(_string) / std::stoll(rhs.toString());
            if (checkTypeOverflow<long double>(nVal, type))
                throw std::runtime_error("Overflow of value !");
            ss << nVal;
        } else
            throw std::runtime_error("Type Error!");

        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator%( IOperand const & rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type <= Float)
        {
            long double nVal = std::stoll(_string) % std::stoll(rhs.toString());
            if (checkTypeOverflow<long double>(nVal, type))
                throw std::runtime_error("Overflow of value !");
            ss << nVal;
        } else
            throw std::runtime_error("Type Error!");

        return (_factory->createOperand(type, ss.str()));
    }

    std::string const &toString( void ) const{
        return _string;
    }

private:
    T                       _value;
    eOperandType            _type;
    std::string             _string;
    int				        _precision;
    const VMFactory         *_factory;

};

#endif //ABSTRACTVM_OPERANDS_HPP
