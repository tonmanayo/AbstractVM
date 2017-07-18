//
// Created by Tony MACK on 2017/07/18.
//

#include <iostream>
#include "ErrorHandle.hpp"

ErrorHandle::ErrorHandle(const char *message): _message(message) {
  //  std::cout << "Error occurred " << message << std::endl;
}

ErrorHandle::ErrorHandle(const std::string &message): _message(message) {
    //std::cout << "Error occurred " + message << std::endl;
}

ErrorHandle::~ErrorHandle() {}

const char *ErrorHandle::what() const throw() {
    return _message.c_str();
}

void ErrorHandle::underoverflow(int i) {
    switch (i) {
        case 1:
            _message = "Overflow Error\n";
        case 2:
            _message = "underflow Error\n";
        case 3:
            _message = "Type error Error\n";
    }
}
