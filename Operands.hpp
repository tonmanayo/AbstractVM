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
#include <math.h>
#include "ErrorHandle.hpp"

template <typename T>
class Operands : public IOperand{

private:
    T                       _value;
    eOperandType            _type;
    std::string             _string;
    int				        _precision;
    const VMFactory         *_factory;

public:

    Operands() {}
    Operands(const Operands& rhs) {}
    const Operands&operator=(const Operands&);

    template <typename C>
    bool checkTypeOverflow(C val, eOperandType type) const {
        bool i = false;

            switch (type) {
                case int8:
                    if (val > 127)
                        throw ErrorHandle("Error: Overflow of int8\n");
                    if (val < -128)
                        throw ErrorHandle("Error: Underflow of int8\n");
                case int16:
                    if (val > 32767)
                        throw ErrorHandle("Error: Overflow of int16\n");
                    if (val < -32768)
                        throw ErrorHandle("Error: Under of int16\n");
                case int32:
                    if (val > 2147483647)
                        throw ErrorHandle("Error: Overflow of int32\n");
                    if (val < -2147483648)
                        throw ErrorHandle("Error: Underflow of int32\n");
                case Float:
                    if (val > FLT_MAX)
                        throw ErrorHandle("Error: Overflow of Float\n");
                    if (val < -FLT_MAX - 1)
                        throw ErrorHandle("Error: Underflow of Float\n");
                case Double:
                    if (val > DBL_MAX)
                        throw ErrorHandle("Error: Overflow of Double\n");
                    if (val < -DBL_MAX - 1)
                        throw ErrorHandle("Error: Underflow of Double\n");
                default:
                    i = true;
            }

        return i;
    }

    int getPrecision(void) const{
        return _precision;
    }

    eOperandType getType(void) const{
        return _type;
    }

    Operands(std::string const &val, eOperandType type, int precision, const VMFactory *factory): _type(type), _precision(precision), _factory(factory) {
        try {
            if (type < Float) {
                long long nVal = std::stoll(val);
                checkTypeOverflow<long long>(nVal, type);
                _value = static_cast<T>(nVal);
                std::stringstream c_out;
                c_out << std::setprecision(precision) << nVal;
                _string = c_out.str();
            } else {
                long double nVal = std::stold(val);
                checkTypeOverflow<long double>(nVal, type);
                _value = static_cast<T>(nVal);
                std::stringstream c_out;
                c_out << std::setprecision(precision) << nVal;
                _string = c_out.str();
            }
        } catch (std::out_of_range range) {
            std::cout << range.what();
        } catch (ErrorHandle &errorHandle) {
            std::cout << errorHandle.what() << std::endl;
        }
    }

    IOperand const *operator+(IOperand const &rhs) const throw(){
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
	    std::stringstream ss;

        try {
            long double nVal = std::stold(_string) + std::stold(rhs.toString());
            checkTypeOverflow<long double>(nVal, type);
            ss << nVal;
        } catch (ErrorHandle &errorHandle) {
            std::cout << errorHandle.what() << " \noverflow\n";
        } catch (std::out_of_range range) {
            std::cout << range.what();
        }
        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator-( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        try {
            long double nVal = std::stold(_string) - std::stold(rhs.toString());
            if (!checkTypeOverflow<long double>(nVal, type))
                throw ;
            ss << nVal;
        } catch (ErrorHandle errorHandle) {
            std::cout << errorHandle.what() << std::endl;
        } catch (std::out_of_range range) {
            std::cout << range.what();
    }
        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator*( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        try {
            long double nVal = std::stold(_string) * std::stold(rhs.toString());
            if (!checkTypeOverflow<long double>(nVal, type))
                throw ;
            ss << nVal;
        } catch (ErrorHandle errorHandle) {
            std::cout << errorHandle.what() << std::endl;
        } catch (std::out_of_range range) {
            std::cout << range.what();
        }
        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator/( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        try {
            if (_string.c_str() == "0" || rhs.toString() == "0")
                throw ErrorHandle("Can't Divide by 0\n");
            long double nVal = std::stold(_string) / std::stold(rhs.toString());
            if (!checkTypeOverflow<long double>(nVal, type))
                throw;
            ss << nVal;
        } catch (ErrorHandle errorHandle) {
            std::cout << errorHandle.what();
        } catch (std::out_of_range range) {
        std::cout << range.what();
        }
        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator%( IOperand const & rhs ) const {
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        try {
            long double nVal = fmodl(std::stold(_string), std::stold(rhs.toString()));
            if (!checkTypeOverflow<long double>(nVal, type))
                throw;
            ss << nVal;
        } catch (ErrorHandle errorHandle) {
            std::cout << errorHandle.what();
        } catch (std::out_of_range range) {
            std::cout << range.what();
        }
        return (_factory->createOperand(type, ss.str()));
    }

    std::string const &toString( void ) const {
        return _string;
    }
};

#endif //ABSTRACTVM_OPERANDS_HPP
