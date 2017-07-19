#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Stackstuff.hpp"
#include "ErrorHandle.hpp"
#include <math.h>
#include <vector>


int main(int argc, char **argv) {
    bool sEnd = false;
    std::string input;
	Stackstuff stackstuff("0");
	std::ifstream myfile;
	std::vector<std::string> sCommands;

	if (argc == 2) {
		myfile.open(argv[1]);
		if (!myfile) {
			std::cout << "Could not open file\n";
			return -1;
		}
	}

	while(1) {
		if (argc == 1) {
			getline(std::cin, input);
			sCommands.push_back(input);
		}
		else if (argc == 2) {
			getline(myfile, input);
			sCommands.push_back(input);
		}
		if (input == ";;" )
			break ;
	}
    try {
        for (unsigned int i = 0; i < sCommands.size(); i++) {
            if (sCommands.at(i) == ";;") {
                if (!sEnd)
                    throw ErrorHandle("Error: No exit command called before end of program! \n");
                break;
            } else if (sCommands.at(i)[0] == ';' && sCommands.at(i)[1] != ';')
                continue;
            else if (std::strncmp(sCommands.at(i).c_str(), "push int8(", 10) == 0) {
                stackstuff.push(sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1),
                                int8);
            } else if (std::strncmp(input.c_str(), "push int16(", 11) == 0) {
                stackstuff.push(sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1),
                                int16);
            } else if (std::strncmp(sCommands.at(i).c_str(), "push int32(", 11) == 0) {
                stackstuff.push(sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1),
                                int32);
            } else if (std::strncmp(sCommands.at(i).c_str(), "push float(", 11) == 0) {
                stackstuff.push(sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1),
                                Float);
            } else if (std::strncmp(sCommands.at(i).c_str(), "push double(", 12) == 0) {
                stackstuff.push(sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1),
                                Double);
            } else if (std::strncmp(sCommands.at(i).c_str(), "pop", 3) == 0 && sCommands.at(i).length() == 3) {
                stackstuff.pop("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "dump", 4) == 0 && sCommands.at(i).length() == 4) {
                stackstuff.dump("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "mul", 3) == 0 && sCommands.at(i).length() == 3) {
                stackstuff.mul("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "sub", 3) == 0 && sCommands.at(i).length() == 3) {
                stackstuff.sub("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "add", 3) == 0 && sCommands.at(i).length() == 3) {
                stackstuff.add("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "div", 3) == 0 && sCommands.at(i).length() == 3) {
                stackstuff.div("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "mod", 3) == 0 && sCommands.at(i).length() == 3) {
                stackstuff.mod("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "print", 5) == 0 && sCommands.at(i).length() == 5) {
                stackstuff.print("", int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "assert int8(", 12) == 0) {
                int i8 = std::stoi(
                        sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1));
                std::stringstream ss;
                ss << i8;
                stackstuff.assert(ss.str(), int8);
            } else if (std::strncmp(sCommands.at(i).c_str(), "assert int16(", 13) == 0) {
                int i16 = std::stoi(
                        sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1));
                std::stringstream ss;
                ss << i16;
                stackstuff.assert(ss.str(), int16);
            } else if (std::strncmp(sCommands.at(i).c_str(), "assert int32(", 13) == 0) {
                int i32 = std::stoi(
                        sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1));
                std::stringstream ss;
                ss << i32;
                stackstuff.assert(ss.str(), int32);
            } else if (std::strncmp(sCommands.at(i).c_str(), "assert float(", 13) == 0) {
                float ifloat = std::stof(
                        sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1));
                std::stringstream ss;
                ss << ifloat;
                stackstuff.assert(ss.str(), Float);
            } else if (std::strncmp(sCommands.at(i).c_str(), "assert double(", 14) == 0) {
                double idbl = std::stod(
                        sCommands.at(i).substr(sCommands.at(i).find("(") + 1, sCommands.at(i).find(")") - 1));
                std::stringstream ss;
                ss << idbl;
                stackstuff.assert(ss.str(), Double);
            } else if (std::strncmp(sCommands.at(i).c_str(), "exit", 4) == 0 && sCommands.at(i).length() == 4) {
                sEnd = true;
            } else
                throw ErrorHandle("Error: instruction Unknown\n");
        }
    } catch (ErrorHandle &errorHandle) {
        std::cout << errorHandle.what() << std::endl;
    }
    return 0;
}