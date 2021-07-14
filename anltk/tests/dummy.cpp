
#include "anltk/anltk_api.h"
#include <algorithm>
#include <iostream>

#include <MemoryMapped.h>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto timeFuncInvocation = [](auto&& func, auto&&... params) {
    // get time before function invocation
    const auto& start = std::chrono::high_resolution_clock::now();
    // function invocation using perfect forwarding
    std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
    // get time after function invocation
    const auto& stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
};

int main(int argc, char** argv)
{
    std::string file_name = argv[1];
    std::ifstream t(file_name.c_str());

    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    // MemoryMapped data(file_name.c_str());
    // const char* str = (const char*) data.getData();

    std::ofstream out_file;
    out_file.open("utfcpp.txt");
    std::string line;
    ANLTK_Preprocessor* pp = anltk_preprocessor_new();
       std::string output;
    std::cout<< timeFuncInvocation([&]() {
        // while (std::getline(t, line))
        {
            // line contains the current line
         

            output = anltk_preprocessor_remove_tashkeel(pp, str.c_str());
            // out_file << output << '\n';
        }
    }) << std::endl;;
    anltk_preprocessor_free(pp);
    out_file << output ;
    // مرحبا  بكم�!
}
