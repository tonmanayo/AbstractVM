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
	std::ifstream myfile;
	if (argc == 2) {
		myfile.open(argv[1]);
		if (!myfile) {
			std::cout << "Could not open file\n";
			return -1;
		}
	}
    while(!sEnd){

       if (argc == 1)
        getline(std::cin, input);
       else if (argc == 2)
           getline(myfile, input);
       else {
	       std::cout << "argument error\n";
	       break;
       }

        if (input == ";;")
            sEnd = true ;
        else if (input[0] == ';' && input[1] != ';')
            continue;
        else if (std::strncmp(input.c_str(), "push int8(", 10) == 0){
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), int8);
        } else if (std::strncmp(input.c_str(), "push int16(", 11) == 0){
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), int16);
        } else if (std::strncmp(input.c_str(), "push int32(", 11) == 0){
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), int32);
        } else if (std::strncmp(input.c_str(), "push float(", 11) == 0){
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), Float);
        } else if (std::strncmp(input.c_str(), "push double(", 12) == 0){
	        stackstuff.push(input.substr(input.find("(") + 1, input.find(")") - 1), Double);
        } else if (std::strncmp(input.c_str(), "pop", 3) == 0 && input.length() == 3){
	        stackstuff.pop("", int8);
        } else if (std::strncmp(input.c_str(), "dump", 4) == 0 && input.length() == 4){
	        stackstuff.dump("", int8);
        } else if (std::strncmp(input.c_str(), "mul", 3) == 0 && input.length() == 3){
	        stackstuff.mul("", int8);
        } else if (std::strncmp(input.c_str(), "sub", 3) == 0 && input.length() == 3){
	        stackstuff.sub("", int8);
        } else if (std::strncmp(input.c_str(), "add", 3) == 0 && input.length() == 3){
	        stackstuff.add("", int8);
        } else if (std::strncmp(input.c_str(), "div", 3) == 0 && input.length() == 3){
	            stackstuff.div("", int8);
        } else if (std::strncmp(input.c_str(), "mod", 3) == 0 && input.length() == 3){
	        stackstuff.mod("", int8);
        } else if (std::strncmp(input.c_str(), "print", 5) == 0 && input.length() == 5){
	        stackstuff.print("", int8);
        } else if (std::strncmp(input.c_str(), "assert ", 7) == 0){
	        if (std::strncmp(input.c_str(), "assert int8(", 12) == 0){
		        int i8 = std::stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i8;
		        stackstuff.assert(ss.str(), int8);
	        }
	        else if (std::strncmp(input.c_str(), "assert int16(", 13) == 0){
		        int i16 = std::stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i16;
		        stackstuff.assert(ss.str(), int16);
	        }
	        else if (std::strncmp(input.c_str(), "assert int32(", 13) == 0){
		        int i32 = std::stoi(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << i32;
		        stackstuff.assert(ss.str(), int32);
	        }
	        else if (std::strncmp(input.c_str(), "assert float(", 13) == 0){
		        float ifloat = std::stof(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << ifloat;
		        stackstuff.assert(ss.str(), Float);
	        }
	        else if (std::strncmp(input.c_str(), "assert double(", 14) == 0){
		        double idbl = std::stod(input.substr(input.find("(") + 1, input.find(")") - 1));
		        std::stringstream ss;
		        ss << idbl;
		        stackstuff.assert(ss.str(), Double);
	        } else {
		        std::cout << "incorrect input\n";
	        }
        } else if (std::strncmp(input.c_str(), "exit", 4) == 0 && input.length() == 4){
            sEnd = true;
        } else
            std::cout << "incorrect input\n";
    }
    return 0;
}