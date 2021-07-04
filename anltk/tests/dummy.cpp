
#include "anltk/anltk_api.h"
#include <algorithm>
#include <iostream>

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

    std::ofstream out_file;
    out_file.open("utfcpp.txt");
    std::string output;
    ANLTK_Preprocessor* pp = anltk_preprocessor_new();
    std::cout << timeFuncInvocation([&]() {
       output = anltk_preprocessor_remove_tashkeel(pp, str.c_str());
    }) << " s" << std::endl;
    out_file << output;
    anltk_preprocessor_free(pp);

    // مرحبا  بكم�!
}
