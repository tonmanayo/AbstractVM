//
// Created by Tony MACK on 2017/07/18.
//

#ifndef ABSTRACTVM_ERRORHANDLE_HPP
#define ABSTRACTVM_ERRORHANDLE_HPP


#include <exception>
#include <string>

class ErrorHandle : public std::exception {
public:
    explicit ErrorHandle(const char* message);
    explicit ErrorHandle(const std::string& message);
    virtual ~ErrorHandle();

    const char* what() const throw() override ;
private:
    std::string _message;
};


#endif //ABSTRACTVM_ERRORHANDLE_HPP
