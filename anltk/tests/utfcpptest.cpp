#include "anltk/anltk.hpp"
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <utf8.h>

int main()
{
	std::cout << "Hello\n";
	anltk::Jumla j("بسم الله الرحمن الرحيم");
	std::cout << j << std::endl;

	for (auto k : j)
	{
		for (auto h : k)
		{
			if (h.prev())
				std::cout << *h.prev();
			std::cout << h;
		}
		std::cout << '\n';
	}

	anltk::Kalima* k = j.first();
	while (k)
	{
		std::cout << *k << " : ";
		anltk::Harf* harf = k->first();

		while (harf)
		{
			if (harf->kalima()->prev())
			{
				std::cout << *harf->kalima()->prev()->last() << std::endl;
			}
			std::cout << harf->to_string() << " ";
			harf = harf->next();
		}
		std::cout << std::endl;
		k = k->next();
	}
}