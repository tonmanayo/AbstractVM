//
// Created by Tony MACK on 2017/06/28.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP

#include <string>

enum eOperandType {
    int8 = 0,
    int16,
    int32,
    Float,
    Double
};

class IOperand {

public:
    virtual int getPrecision( void ) const = 0;                                     // Precision of the type of the instance
    virtual eOperandType getType( void ) const = 0;                                 // Type of the instance
    virtual IOperand const *operator+(IOperand const &rhs) const = 0;               // Sum
    virtual IOperand const *operator-(IOperand const &rhs) const = 0;               // Difference
    virtual IOperand const *operator*(IOperand const &rhs) const = 0;               // Product
    virtual IOperand const *operator/(IOperand const &rhs) const = 0;               // Quotient
    virtual IOperand const *operator%(IOperand const &rhs) const = 0;               // Modulo
    virtual std::string const &toString(void) const = 0;                            // String representation of the instance
    virtual ~IOperand( void ) {}                                                    // destructor

};
#endif //ABSTRACTVM_IOPERAND_HPP
