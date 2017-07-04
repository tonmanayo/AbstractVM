#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <iostream>



int main(int argc, char **argv) {
    bool sEnd = false;
    std::string input;

    int count = 0;
    while(!sEnd){

       if (argc <= 1)
        getline(std::cin, input);
       else {
           int num = 0;
           std::ifstream myfile(argv[1]);
           while (getline(myfile, input)) {
               if (num == count)
                   break ;
               num++;
           }
           myfile.close();
       }
        if (input == ";;")
            sEnd = true ;
        else if (input[0] == ';' && input[1] != ';')
            continue;
        else if (std::strncmp(input.c_str(), "push int8(", 10) == 0){
            int i8 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << i8 << std::endl;
        } else if (std::strncmp(input.c_str(), "push int16(", 11) == 0){
            int i16 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << i16 << std::endl;
        } else if (std::strncmp(input.c_str(), "push int32(", 11) == 0){
            int i32 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << i32 << std::endl;
        } else if (std::strncmp(input.c_str(), "push float(", 11) == 0){
            float ifloat = stof(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << ifloat << std::endl;
        } else if (std::strncmp(input.c_str(), "push double(", 12) == 0){
            double idouble = stod(input.substr(input.find("(") + 1, input.find(")") - 1));
            std::cout << idouble << std::endl;
        } else if (std::strncmp(input.c_str(), "pop", 3) == 0 && input.length() == 3){
            std::cout << "pop\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "dump", 4) == 0 && input.length() == 4){
            std::cout << "dump\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "mul", 3) == 0 && input.length() == 3){
            std::cout << "mul\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "sub", 3) == 0 && input.length() == 3){
            std::cout << "sub\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "div", 3) == 0 && input.length() == 3){
            std::cout << "div\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "mod", 3) == 0 && input.length() == 3){
            std::cout << "mod\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "print", 5) == 0 && input.length() == 5){
            std::cout << "print\n" << std::endl;
        } else if (std::strncmp(input.c_str(), "assert ", 6) == 0 && input.length() == 6){
            int i8 = stoi(input.substr(input.find("t") + 2, input.length() - 1));
            std::cout << i8 << std::endl;
        } else if (std::strncmp(input.c_str(), "exit", 4) == 0 && input.length() == 4){
            sEnd = true;
            std::cout << "exit\n" << std::endl;
        } else
            std::cout << "incorrect input\n";
        count++;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}