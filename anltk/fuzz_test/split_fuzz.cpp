#include <anltk/anltk.hpp>
#include <iostream>
#include <utf8.h>

int main(int argc, char const* argv[])
{

	std::string input;
	std::cin >> input;
	if (utf8::is_valid(input))
	{
		anltk::split(input);
	}

	return 0;
}
