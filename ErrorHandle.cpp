//
// Created by Tony MACK on 2017/07/18.
//

#include <iostream>
#include "ErrorHandle.hpp"

ErrorHandle::ErrorHandle(const char *message) : _message(message) {
  //  std::cout << "Error occurred " << message << std::endl;
}

ErrorHandle::ErrorHandle(const std::string &message) : _message(message) {
    //std::cout << "Error occurred " + message << std::endl;
}

ErrorHandle::~ErrorHandle() {}

const char *ErrorHandle::what() const throw() {
    return _message.c_str();
}