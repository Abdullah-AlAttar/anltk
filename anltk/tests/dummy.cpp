#include <tinyutf8/tinyutf8.h>

#include <algorithm>
#include <iostream>


int main()
{
    tiny_utf8::string str = u8"Hello 🌍 World";

    std::cout << str << std::endl;

    str.erase(std::remove_if(str.begin(), str.end(), [](auto c) { return c == 'W'; }),
              str.end());

    std::cout << str << std::endl;
}