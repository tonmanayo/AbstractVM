//
// Created by tony on 2017/07/11.
//

#include <iostream>
#include "Stackstuff.hpp"
#include "ErrorHandle.hpp"

Stackstuff::Stackstuff()
        : _value("0") {}

Stackstuff::Stackstuff(std::string value )
        : _value(value) {}

Stackstuff::Stackstuff(Stackstuff const &rhs ) {
    _stack = rhs._stack;
    _factory = rhs._factory;
    _type = rhs._type;
    _value = rhs._value;
}

const Stackstuff& Stackstuff::operator=(const Stackstuff &rhs) {
    _value = rhs._value;
    _type = rhs._type;
    _factory = rhs._factory;
    _stack = rhs._stack;
    return *this;
}

Stackstuff::~Stackstuff(){}



void    Stackstuff::push(std::string value, eOperandType type) {
	_type = type;
	_stack.push_front(_factory.createOperand(type, value));
}

void Stackstuff::pop(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() == 0)
            throw ErrorHandle("Error: Can't pop on an empty stack, Pop fail!\n");
        _stack.pop_front();
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::dump(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() == 0)
            throw ErrorHandle("Error: Dump fail!\n");
        std::list<const IOperand *>::iterator itr;
        for (itr = _stack.begin(); itr != _stack.end(); ++itr)
            std::cout << (*itr)->toString() << std::endl;
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::assert(std::string value, eOperandType type){
    try {
        if (_stack.size() == 0)
            throw ErrorHandle("Error: Empty stack! Failed assert\n");
        const IOperand *op = *(_stack.begin());
        if (op->toString() != value)
            throw ErrorHandle("Error: Different Values! assert failed\n");
        if (op->getType() != type)
            throw ErrorHandle("Error: Wrong type! assert failed!\n");
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::add(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {

        if (_stack.size() < 2)
		    throw ErrorHandle("Error: stack to small! add error\n");
	    const IOperand* op1 = *(_stack.begin());
	    _stack.pop_front();
	    const IOperand* op2 = *(_stack.begin());
	    _stack.pop_front();
	    const IOperand* r  = *op1 + *op2;
	    delete op1;
	    delete op2;
	    _stack.push_front(r);
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::sub(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() < 2)
            throw ErrorHandle("Error: stack to small! sub error\n");
        const IOperand *op1 = *(_stack.begin());
        _stack.pop_front();
        const IOperand *op2 = *(_stack.begin());
        _stack.pop_front();
        const IOperand *r = *op2 - *op1;
        delete op1;
        delete op2;
        _stack.push_front(r);
    }  catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::mul(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() < 2)
            throw ErrorHandle("stack to small! mul error\n");
        const IOperand *op1 = *(_stack.begin());
        _stack.pop_front();
        const IOperand *op2 = *(_stack.begin());
        _stack.pop_front();
        const IOperand *r = *op1 * *op2;
        delete op1;
        delete op2;
        _stack.push_front(r);
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::div(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() < 2)
            throw ErrorHandle("Error: stack to small, div error\n");
        const IOperand *op1 = *(_stack.begin());
        _stack.pop_front();
        const IOperand *op2 = *(_stack.begin());
        _stack.pop_front();
        if (op1->toString() == "0" || op2->toString() == "0") {
            throw ErrorHandle("Error: trying to divide by 0\n");
        }
        const IOperand *r = *op2 / *op1;
        delete op1;
        delete op2;
        _stack.push_front(r);
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::mod(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() < 2)
            throw ErrorHandle("Error: stack to small, mod error\n");
        const IOperand *op1 = *(_stack.begin());
        _stack.pop_front();
        const IOperand *op2 = *(_stack.begin());
        _stack.pop_front();
        if (op1->toString() == "0" || op2->toString() == "0") {
            throw ErrorHandle("Error: trying to mod by 0\n");
        }
        const IOperand *r = *op2 % *op1;
        delete op1;
        delete op2;
        _stack.push_front(r);
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::print(std::string value, eOperandType type) {
    (void)value;
    (void)type;
    try {
        if (_stack.size() == 0)
            throw ErrorHandle("Error: empty stack, print\n");
        const IOperand *op1 = *(_stack.begin());
        if (op1->getType() != int8)
            throw ErrorHandle("Error: Can only print 8-bit int\n");
        std::cout << static_cast<char>(std::stoi(op1->toString())) << std::endl;
    } catch (ErrorHandle errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
}

void Stackstuff::exit(std::string value, eOperandType type) {
    (void)value;
    (void)type;
	std::exit(0);
}



