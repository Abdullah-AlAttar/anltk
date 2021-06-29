#include <tinyutf8/tinyutf8.h>

#include <algorithm>
#include <iostream>


int main()
{
    tiny_utf8::string str = "!!مرحبا !! بكم!";    std::cout << str << std::endl;
// مرحبا  بكم
    str.erase(std::remove_if(str.begin(), str.end(), [](char32_t c) { return c == U'!'; }),
              str.end());
    std::cout << str << std::endl;
    // مرحبا  بكم�!
}

