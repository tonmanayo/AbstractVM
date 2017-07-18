//
// Created by tony on 2017/07/11.
//

#include <iostream>
#include "Stackstuff.hpp"

Stackstuff::Stackstuff(std::string value )
		: _value(value) {}

void    Stackstuff::push(std::string value, eOperandType type) {
	_type = type;
	_stack.push_front(_factory.createOperand(type, value));
}

void Stackstuff::pop(std::string value, eOperandType type) {
	if (_stack.size() == 0)
		throw std::runtime_error("Pop fail!");
	_stack.pop_front();
}

void Stackstuff::dump(std::string value, eOperandType type) {
	if (_stack.size() == 0)
		throw std::runtime_error("Dump fail!");
	std::list<const IOperand*>::iterator itr;
	for (itr = _stack.begin(); itr != _stack.end(); ++itr)
		std::cout << (*itr)->toString() << std::endl;
}

void Stackstuff::assert(std::string value, eOperandType type){
	if (_stack.size() == 0)
		throw std::runtime_error("Empty stack! Failed assert");
	const IOperand* op = *(_stack.begin());
	if (op->toString() != value)
		throw std::runtime_error("Different Values! assert failed");
	if (op->getType() != type)
		throw std::runtime_error("Wrong type! assert failed!");
}

void Stackstuff::add(std::string value, eOperandType type) {
	if (_stack.size() < 2)
		throw std::runtime_error("stack to small! add error");
	const IOperand* op1 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* op2 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* r  = *op1 + *op2;
	delete op1;
	delete op2;
	_stack.push_front(r);
}

void Stackstuff::sub(std::string value, eOperandType type) {
	if (_stack.size() < 2)
		throw std::runtime_error("stack to small! sub error");
	const IOperand* op1 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* op2 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* r  = *op2 - *op1;
	delete op1;
	delete op2;
	_stack.push_front(r);
}

void Stackstuff::mul(std::string value, eOperandType type) {
	if (_stack.size() < 2)
		throw std::runtime_error("stack to small! mul error");
	const IOperand* op1 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* op2 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* r  = *op1 * *op2;
	delete op1;
	delete op2;
	_stack.push_front(r);
}

void Stackstuff::div(std::string value, eOperandType type) {
	if (_stack.size() < 2)
		throw std::runtime_error("stack to small, div error");
	const IOperand* op1 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* op2 = *(_stack.begin());
	_stack.pop_front();
    if (op1->toString() == "0" || op2->toString() == "0"){
        std::cout << "error trying to divide by 0\n";
        return ;
    }

	const IOperand* r  = *op2 / *op1;
	delete op1;
	delete op2;
	_stack.push_front(r);
}

void Stackstuff::mod(std::string value, eOperandType type) {
	if (_stack.size() < 2)
		throw std::runtime_error("stack to small mod error");
	const IOperand* op1 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* op2 = *(_stack.begin());
	_stack.pop_front();
	const IOperand* r  = *op2 % *op1;
	delete op1;
	delete op2;
	_stack.push_front(r);
}

void Stackstuff::print(std::string value, eOperandType type) {
	if (_stack.size() == 0)
		throw std::runtime_error("can't print empty stack");
	const IOperand* op1 = *(_stack.begin());
	if (op1->getType() != int8)
		throw std::runtime_error("Print instruction on no 8-bit integer");
	std::cout << static_cast<char>(std::stoi(op1->toString())) << std::endl;
}

void Stackstuff::exit(std::string value, eOperandType type) {
	std::exit(0);
}

void    Stackstuff::end(std::string value, eOperandType type){}

Stackstuff::~Stackstuff() {}