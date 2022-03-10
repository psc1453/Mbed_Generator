//
// Created by psc on 2022/2/24.
//

#include "replace.h"

std::string replace(std::string str, const char* src, const char* tgt)
{
    int pos;
    pos = str.find(src);
    while (pos != -1)
    {
        // str.length()求字符的长度，注意str必须是string类型
        str.replace(pos, std::string(src).length(), tgt);
        pos = str.find(src);
    }
    return str;
}

std::string replace_dir(std::string src, std::string name)
{
    int index = src.find_last_of('/');
    std::string path = src.substr(0, index + 1);
    std::string new_dir = path + name;
    return new_dir;
}