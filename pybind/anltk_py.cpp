#include "anltk/anltk.hpp"




#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>



namespace py = pybind11;


PYBIND11_MODULE(anltk, m)
{
	m.def("is_tashkeel", &anltk::is_tashkeel_c, py::arg("c"));
}