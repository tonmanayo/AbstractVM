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
    bool checkTypeOverflow(C val, eOperandType type) const throw(){
        bool i = false;
        switch (type) {
            case int8:
                if (val > 127 )
                    throw ErrorHandle("Overflow of int8\n");
                if (val < -128)
                    throw ErrorHandle("Underflow of int8\n");
            case int16:
                if (val > 32767)
                    throw ErrorHandle("Overflow of int16\n");
                if (val < -32768)
                    throw ErrorHandle("Under of int16\n");
            case int32:
                if (val > 2147483647)
                    throw ErrorHandle("Overflow of int32\n");
                if (val < -2147483648)
                    throw ErrorHandle("Underflow of int32\n");
            case Float:
                if (val > FLT_MAX)
                    throw ErrorHandle("Overflow of Float\n");
                if (val < -FLT_MAX - 1)
                    throw ErrorHandle("Underflow of Float\n");
            case Double:
                if (val > DBL_MAX)
                    throw ErrorHandle("Overflow of Double\n");
                if (val < -DBL_MAX - 1)
                    throw ErrorHandle("Underflow of Double\n");
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

    Operands(std::string const &val, eOperandType type, int precision, const VMFactory *factory): _type(type), _precision(precision), _factory(factory){
        try {
            if (type < Float) {
                long long nVal = std::stoll(val);
                if (!checkTypeOverflow<long long>(nVal, type))
                    throw ;
                _value = static_cast<T>(nVal);
                std::stringstream c_out;
                c_out << std::setprecision(precision) << nVal;
                _string = c_out.str();
            } else {
                long double nVal = std::stold(val);
                if (!checkTypeOverflow<long long>(nVal, type))
                    throw ;
                _value = static_cast<T>(nVal);
                std::stringstream c_out;
                c_out << std::setprecision(precision) << nVal;
                _string = c_out.str();
            }
        } catch (ErrorHandle errorHandle) {
            std::cout << errorHandle.what();
        }
    }

    IOperand const *operator+(IOperand const &rhs) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
	    int precision = _precision >= rhs.getPrecision() ? _precision: rhs.getPrecision();
	    std::stringstream ss;

        //if (type < Float) {
        try {
            long double nVal = std::stold(_string) + std::stold(rhs.toString());
            if (!checkTypeOverflow<long long>(nVal, type))
                throw ;


            ss << nVal;

        //} else {
//	        long double nVal = std::stold(_string) + std::stold(rhs.toString());
//	        if (checkTypeOverflow<long double>(nVal, type))
//		        throw std::runtime_error("Overflow of value !");
//	        ss << std::setprecision(_precision) << nVal;
//        }
            return (_factory->createOperand(type, ss.str()));
        } catch (ErrorHandle errorHandle) {
            std::cout << errorHandle.what() << " overflow\n";
        }
    }

    IOperand const *operator-( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type < Float) {
            long long nVal = std::stoll(_string) - std::stoll(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << nVal;
        } else {
	        long double nVal = std::stold(_string) - std::stold(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << std::setprecision(_precision) << nVal;
        }

        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator*( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type < Float) {
            long long nVal = std::stoll(_string) * std::stoll(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << nVal;
        } else {
	        long double nVal = std::stold(_string) * std::stold(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << std::setprecision(_precision) << nVal;
        }
        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator/( IOperand const &rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type < Float) {
            long long nVal = std::stoll(_string) / std::stoll(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << nVal;
        } else {
	        long double nVal = std::stold(_string) / std::stold(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << std::setprecision(_precision) << nVal;
        }
        return (_factory->createOperand(type, ss.str()));
    }

    IOperand const *operator%( IOperand const & rhs ) const{
        eOperandType type = _type >= rhs.getType() ? _type : rhs.getType();
        std::stringstream ss;

        if (type < Float) {
            long long nVal = std::stoll(_string) % std::stoll(rhs.toString());
            checkTypeOverflow<long long>(nVal, type);

            ss << nVal;
        } else {
	        long double nVal = fmodl(std::stold(_string), std::stold(rhs.toString()));
            checkTypeOverflow<long long>(nVal, type);

            ss << std::setprecision(_precision) << nVal;
        }
        return (_factory->createOperand(type, ss.str()));
    }

    std::string const &toString( void ) const{
        return _string;
    }
};

#endif //ABSTRACTVM_OPERANDS_HPP
