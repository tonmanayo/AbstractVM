#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>


int main() {
    bool sEnd = false;
    std::stringstream s;
    std::string input;

    while(!sEnd){
        getline(std::cin, input);
        if (input == ";;")
            sEnd = true ;
        if (input[0] == ';' && input[1] != ';')
            continue;
        if (std::strncmp(input.c_str(), "push int8(", 9) == 0){
            int i8 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << i8 << std::endl;
        }
        if (std::strncmp(input.c_str(), "push int16(", 9) == 0){
            int i16 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << i16 << std::endl;
        }
        if (std::strncmp(input.c_str(), "push int32(", 10) == 0){
            int i32 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << i32 << std::endl;
        }
        if (std::strncmp(input.c_str(), "push float(", 11) == 0){
            float ifloat = stof(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << ifloat << std::endl;
        }
        if (std::strncmp(input.c_str(), "push double(", 12) == 0){
            double idouble = stod(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << idouble << std::endl;
        }
        if (std::strncmp(input.c_str(), "pop", 3) == 0){

            std::cout << "pop\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "dump", 4) == 0){

            std::cout << "dump\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "mul", 4) == 0){

            std::cout << "mul\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "sub", 4) == 0){

            std::cout << "sub\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "div", 4) == 0){

            std::cout << "div\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "mod", 4) == 0){

            std::cout << "mod\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "print", 4) == 0){

            std::cout << "print\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "exit", 4) == 0){

            std::cout << "exit\n" << std::endl;
        }
        if (std::strncmp(input.c_str(), "assert ", 7) == 0){
            int i8 = stoi(input.substr(input.find("t") + 2, input.length() - 1));
            std::cout << i8 << std::endl;
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}