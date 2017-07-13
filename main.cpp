#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Stackstuff.hpp"
#include <math.h>




int main(int argc, char **argv) {
    bool sEnd = false;
    std::string input;
	Stackstuff stackstuff("0");

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
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), int8);
            std::cout << i8 << std::endl;
        } else if (std::strncmp(input.c_str(), "push int16(", 11) == 0){
            int i16 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), int16);
            std::cout << i16 << std::endl;
        } else if (std::strncmp(input.c_str(), "push int32(", 11) == 0){
            int i32 = stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), int32);
	        std::cout << i32 << std::endl;
        } else if (std::strncmp(input.c_str(), "push float(", 11) == 0){
            float ifloat = stof(input.substr(input.find("(") + 1, input.find(")") - 1));
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), Float);
	        std::cout << ifloat << std::endl;
        } else if (std::strncmp(input.c_str(), "push double(", 12) == 0){
            double idouble = stod(input.substr(input.find("(") + 1, input.find(")") - 1));
	        std::cout << idouble << std::endl;
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), Double);
        } else if (std::strncmp(input.c_str(), "pop", 3) == 0 && input.length() == 3){
            std::cout << "pop\n" << std::endl;
	        stackstuff.pop("", int8);
        } else if (std::strncmp(input.c_str(), "dump", 4) == 0 && input.length() == 4){
            std::cout << "dump\n" << std::endl;
	        stackstuff.dump("", int8);
        } else if (std::strncmp(input.c_str(), "mul", 3) == 0 && input.length() == 3){
            std::cout << "mul\n" << std::endl;
	        stackstuff.mul("", int8);
        } else if (std::strncmp(input.c_str(), "sub", 3) == 0 && input.length() == 3){
            std::cout << "sub\n" << std::endl;
	        stackstuff.sub("", int8);
        } else if (std::strncmp(input.c_str(), "add", 3) == 0 && input.length() == 3){
	        std::cout << "add\n" << std::endl;
	        stackstuff.add("", int8);
        } else if (std::strncmp(input.c_str(), "div", 3) == 0 && input.length() == 3){
            std::cout << "div\n" << std::endl;
	            stackstuff.div("", int8);
        } else if (std::strncmp(input.c_str(), "mod", 3) == 0 && input.length() == 3){
            std::cout << "mod\n" << std::endl;
	        stackstuff.mod("", int8);
        } else if (std::strncmp(input.c_str(), "print", 5) == 0 && input.length() == 5){
            std::cout << "print\n" << std::endl;
	        stackstuff.print("", int8);
        } else if (std::strncmp(input.c_str(), "assert ", 7) == 0){
	        if (std::strncmp(input.c_str(), "assert int8(", 12) == 0){
		        int i7 = std::stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i7;
		        stackstuff.assert(ss.str(), int8);
	        }
	        else if (std::strncmp(input.c_str(), "assert int16(", 13) == 0){
		        int i7 = std::stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i7;
		        stackstuff.assert(ss.str(), int16);
	        }
	        else if (std::strncmp(input.c_str(), "assert int32(", 13) == 0){
		        int i7 = std::stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i7;
		        stackstuff.assert(ss.str(), int32);
	        }
	        else if (std::strncmp(input.c_str(), "assert float(", 13) == 0){
		        float i7 = std::stof(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i7;
		        stackstuff.assert(ss.str(), Float);
	        }
	        else if (std::strncmp(input.c_str(), "assert double(", 14) == 0){
		        double i7 = std::stod(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i7;
		        stackstuff.assert(ss.str(), Double);
	        } else {
		        std::cout << "incorrect input\n";
	        }
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