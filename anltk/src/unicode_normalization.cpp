
#ifndef BUILDING_PYBIND11

#include "anltk/anltk.hpp"
#include <utf8proc.h>

namespace anltk
{

std::string normalize_unicode(const std::string& input, NormalizeMode mode)
{

	std::string output;
	char* result;

	switch (mode)
	{
	case NormalizeMode::NFD:
		result = (char*)utf8proc_NFD((unsigned char*)input.c_str());
		break;
	case NormalizeMode::NFC:
		result = (char*)utf8proc_NFC((unsigned char*)input.c_str());
		break;

	case NormalizeMode::NFKC:
		result = (char*)utf8proc_NFKC((unsigned char*)input.c_str());
		break;
	case NormalizeMode::NFKD:
		result = (char*)utf8proc_NFKD((unsigned char*)input.c_str());
		break;
	default:
		break;
	}
	if (result)
	{
		output = std::string(result);
		free(result);
		result = NULL;
	}
	return output;
}

} // namespace anltk

#endif