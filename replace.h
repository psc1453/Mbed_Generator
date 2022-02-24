//
// Created by psc on 2022/2/24.
//

#ifndef Mbed_Generator_REPLACE_H
#define Mbed_Generator_REPLACE_H

#include <string>

std::string replace(std::string str, const char* src, const char* tgt);
std::string replace_dir(std::string src, std::string name);

#endif //Mbed_Generator_REPLACE_H
