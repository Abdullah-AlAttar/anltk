
#include "anltk/anltk.hpp"
#include "utf8.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
auto timeFuncInvocation = [](auto&& func, auto&&... params) {
    // get time before function invocation
    const auto& start = std::chrono::high_resolution_clock::now();
    // function invocation using perfect forwarding
    std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
    // get time after function invocation
    const auto& stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
};

int main(int argc, char const* argv[])
{
    std::string file_name = argv[1];
    std::ifstream t(file_name.c_str());

    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    std::ofstream out_file;
    out_file.open("utfcpp.txt");


    // anltk::Transliterator trans(anltk::Mappings::AR2BW);


    // out_file << trans.convert(str.c_str());

    // const char* c_str = str.c_str();

    // std::string str_32;

    // std::cout<<strlen(c_str) << std::endl;

    // std::cout << timeFuncInvocation([&]() {
    //     auto start = c_str;
    //     auto end   = c_str + strlen(c_str);

    //     // utf8::next()
    //     while (start < end)
    //     {
    //         char32_t next = utf8::next(start, end);
    //         if (anltk::is_tashkeel(next))
    //             continue;
    //         //  std::cout<< "ues\n";
    //         // str_32 += next;
    //         utf8::append(next, str_32);
    //         // out_file << U'w';
    //     }
    //     // str_32 = utf8::utf8to32(str);

    //     // str_32.erase(std::remove_if(str_32.begin(), str_32.end(),
    //     //                             [](char32_t c) { return anltk::is_tashkeel(c); }),
    //     //              str_32.end());
    // }) << " ms.\n";

    // out_file << str_32;
    out_file.close();
    // std::cout << line.size() << " " << str_32.size() << std::endl;
    // std::cout<< str_32 << " "<< str_32.size()<<std::endl;
    return 0;
}
