//
// Created by tony on 2017/07/11.
//

#ifndef ABSTRACTVM_STACKSTUFF_HPP
#define ABSTRACTVM_STACKSTUFF_HPP


#include <map>
#include <list>
#include "VMFactory.hpp"
#include "IOperand.hpp"


class Stackstuff {
private:
	std::string                                     _value;
	std::list<const IOperand*>                      _stack;
	std::map<int, void(Stackstuff::*)(std::string, eOperandType)> _operations;
	VMFactory                                       _factory;
	eOperandType                                    _type;

public:
	Stackstuff();
	Stackstuff(const Stackstuff&);
	const Stackstuff& operator=(const Stackstuff&);
	Stackstuff(std::string);
	//void    run();

	void    push(std::string value, eOperandType type);
	void    pop(std::string value, eOperandType type);
	void    dump(std::string value, eOperandType type);
	void    assert(std::string value, eOperandType type);
	void    add(std::string value, eOperandType type);
	void    sub(std::string value, eOperandType type);
	void    mul(std::string value, eOperandType type);
	void    div(std::string value, eOperandType type);
	void    mod(std::string value, eOperandType type);
	void    print(std::string value, eOperandType type);
	void    exit(std::string value, eOperandType type);
	void    end(std::string value, eOperandType type);

	~Stackstuff();


};


#endif //ABSTRACTVM_STACKSTUFF_HPP
