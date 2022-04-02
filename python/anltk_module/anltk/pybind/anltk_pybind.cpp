#include "anltk/anltk.hpp"

#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

using map_char_char_t = std::map<anltk::char_t, anltk::char_t>;
using map_sv_sv_t     = std::map<anltk::string_view_t, anltk::string_view_t>;

PYBIND11_MAKE_OPAQUE(map_char_char_t);
PYBIND11_MAKE_OPAQUE(map_sv_sv_t);

PYBIND11_MODULE(anltk_pybind, m)
{

	py::bind_map<map_char_char_t>(m, "MapCharChar");
	py::bind_map<map_sv_sv_t>(m, "MapSvSv");

	{
		// clang-format off
        m.def("tafqeet", &anltk::tafqeet,
              py::arg("num"),
              py::arg("is_ordinal") = false,
              py::arg("is_feminine") = false);

		py::class_<anltk::TafqitOptions>(m, "TafqitOptionsType")
            .def(py::init<>())
            .def_readwrite("is_feminine",&anltk::TafqitOptions::is_feminine)
            .def_readwrite("use_comma",&anltk::TafqitOptions::use_comma)
            .def_readwrite("split_hundred",&anltk::TafqitOptions::split_hundred)
            .def_readwrite("use_miah",&anltk::TafqitOptions::use_miah)
            .def_readwrite("use_billion",&anltk::TafqitOptions::use_billion)
            .def_readwrite("has_followup_text",&anltk::TafqitOptions::has_followup_text)
            .def_readwrite("is_accusative",&anltk::TafqitOptions::is_accusative)
            .def_readwrite("subjects",&anltk::TafqitOptions::subjects)
            .def_readwrite("use_legal_form",&anltk::TafqitOptions::use_legal_form)
            ;
        m.def("tafqit", &anltk::tafqit,
              py::arg("number"),
              py::arg("opts"));
			  
        py::enum_<anltk::CharMapping>(m, "CharMapping")
            .value("AR2BW", anltk::CharMapping::AR2BW)
            .value("BW2AR", anltk::CharMapping::BW2AR)
            .value("AR2SBW", anltk::CharMapping::AR2SBW)
            .value("SBW2AR", anltk::CharMapping::SBW2AR)
            .export_values();
            
        m.def("transliterate", &anltk::transliterate,
              py::arg("input"),
              py::arg("mapping"));
		// clang-format on
		m.def("tokenize_words", &anltk::tokenize_words, py::arg("input"));

		m.def("is_tashkeel", &anltk::is_tashkeel, py::arg("c"),
		      "Checks where a character is valid haraka");

		m.def("is_arabic_alpha", &anltk::is_arabic_alpha, py::arg("c"));
		m.def("is_small", &anltk::is_small, py::arg("c"));
		m.def("is_indic_digit", &anltk::is_indic_digit, py::arg("c"));
		m.def("is_valid_kalima", anltk::is_valid_kalima, py::arg("word"));
		m.def("is_shamsi", &anltk::is_shamsi, py::arg("c"));
		m.def("is_qamari", &anltk::is_qamari, py::arg("c"));

		m.def("remove_tashkeel", &anltk::remove_tashkeel, py::arg("input"));
		m.def("remove_small", &anltk::remove_small, py::arg("input"));
		m.def("remove_non_alpha", &anltk::remove_non_alpha, py::arg("input"), py::arg("stop_list"));
		m.def("remove_non_alphanumeric", &anltk::remove_non_alphanumeric, py::arg("input"),
		      py::arg("stop_list"));
		m.def("remove_non_alpha_and_tashkeel", &anltk::remove_non_alpha_and_tashkeel,
		      py::arg("input"), py::arg("stop_list"));

		m.def("remove_non_alphanumeric_and_tashkeel", &anltk::remove_non_alphanumeric_and_tashkeel,
		      py::arg("input"), py::arg("stop_list"));
		m.def("remove_kasheeda", &anltk::remove_kasheeda, py::arg("input"));
		m.def("normalize_hamzat", &anltk::normalize_hamzat, py::arg("input"));
		m.def("normalize_to_teh", &anltk::normalize_to_teh, py::arg("input"));

		m.def("normalize_to_heh", &anltk::normalize_to_heh, py::arg("input"));

		m.def("duplicate_shadda_letter", &anltk::duplicate_shadda_letter, py::arg("input"));
		m.def("remove_if", &anltk::remove_if, py::arg("input"), py::arg("stop_list"),
		      py::arg("func"));
		m.def("fold_white_spaces", &anltk::fold_white_spaces, py::arg("input"));
		m.def("fold_if", &anltk::fold_if, py::arg("input"), py::arg("func"));
		m.def("split", &anltk::split, py::arg("input"), py::arg("delimeters"),
		      py::arg("keep_delimeters"));

		m.def("tokenize_if", &anltk::tokenize_if, py::arg("input"), py::arg("funcs"));

		m.def(
		    "replace",
		    [](anltk::string_view_t input, const py::dict& chars_map)
		    {
			    map_char_char_t cpp_map;
			    for (const auto& item : chars_map)
			    {
				    cpp_map[item.first.cast<anltk::char_t>()] = item.second.cast<anltk::char_t>();
			    }
			    return anltk::replace(input, cpp_map);
		    },
		    py::arg("input"), py::arg("chars_map"));

		m.def(
		    "replace_str",
		    [](anltk::string_view_t input, const py::dict& chars_map)
		    {
			    map_sv_sv_t cpp_map;
			    for (const auto& item : chars_map)
			    {
				    auto key     = item.first.cast<anltk::string_t>();
				    auto value   = item.second.cast<anltk::string_t>();
				    cpp_map[key] = value;
			    }
			    return anltk::replace_str(input, cpp_map);
		    },
		    py::arg("input"), py::arg("chars_map"));

		m.def("replace_if", &anltk::replace_if, py::arg("input"), py::arg("func"),
		      py::arg("replacement"));

		py::class_<anltk::NoiseGenerator>(m, "NoiseGenerator")
		    .def(py::init<>())
			.def("set_seed", &anltk::NoiseGenerator::set_seed, py::arg("seed"))
		    .def("insert_random_chars", &anltk::NoiseGenerator::insert_random_chars,
		         py::arg("input"), py::arg("n"))
		    .def("swap_adjacent_chars", &anltk::NoiseGenerator::swap_adjacent_chars,
		         py::arg("input"), py::arg("n"))
		    .def("remove_random_chars", &anltk::NoiseGenerator::remove_random_chars,
		         py::arg("input"), py::arg("n"))
		    .def("replace_random_chars", &anltk::NoiseGenerator::replace_random_chars,
		         py::arg("input"), py::arg("n"))
		    .def("join_random_words", &anltk::NoiseGenerator::join_random_words,
		         py::arg("input"), py::arg("n"))
		    .def("swap_random_words", &anltk::NoiseGenerator::swap_random_words,
		         py::arg("input"), py::arg("n"));
	}

	{
		py::module constants_m = m.def_submodule("constants");

		constants_m.attr("HAMZA")            = anltk::HAMZA;
		constants_m.attr("ALEF_MADDA")       = anltk::ALEF_MADDA;
		constants_m.attr("ALEF_HAMZA_ABOVE") = anltk::ALEF_HAMZA_ABOVE;
		constants_m.attr("WAW_HAMZA_ABOVE")  = anltk::WAW_HAMZA_ABOVE;
		constants_m.attr("ALEF_HAMZA_BELOW") = anltk::ALEF_HAMZA_BELOW;
		constants_m.attr("YEH_HAMZA_ABOVE")  = anltk::YEH_HAMZA_ABOVE;
		constants_m.attr("ALEF_NO_HAMZA")    = anltk::ALEF_NO_HAMZA;
		constants_m.attr("BEH")              = anltk::BEH;
		constants_m.attr("TEH_MARBOOTA")     = anltk::TEH_MARBOOTA;
		constants_m.attr("TEH")              = anltk::TEH;
		constants_m.attr("THEH")             = anltk::THEH;
		constants_m.attr("JEEM")             = anltk::JEEM;
		constants_m.attr("HAH")              = anltk::HAH;
		constants_m.attr("KHAH")             = anltk::KHAH;
		constants_m.attr("DAL")              = anltk::DAL;
		constants_m.attr("THAL")             = anltk::THAL;
		constants_m.attr("REH")              = anltk::REH;
		constants_m.attr("ZAIN")             = anltk::ZAIN;
		constants_m.attr("SEEN")             = anltk::SEEN;
		constants_m.attr("SHEEN")            = anltk::SHEEN;
		constants_m.attr("SAD")              = anltk::SAD;
		constants_m.attr("DAD")              = anltk::DAD;
		constants_m.attr("TAH")              = anltk::TAH;
		constants_m.attr("ZAH")              = anltk::ZAH;
		constants_m.attr("AIN")              = anltk::AIN;
		constants_m.attr("GHAIN")            = anltk::GHAIN;
		constants_m.attr("FEH")              = anltk::FEH;
		constants_m.attr("QAF")              = anltk::QAF;
		constants_m.attr("KAF")              = anltk::KAF;
		constants_m.attr("LAM")              = anltk::LAM;
		constants_m.attr("MEEM")             = anltk::MEEM;
		constants_m.attr("NOON")             = anltk::NOON;
		constants_m.attr("HEH")              = anltk::HEH;
		constants_m.attr("WAW")              = anltk::WAW;
		constants_m.attr("ALEF_MAQSURA")     = anltk::ALEF_MAQSURA;
		constants_m.attr("YEH")              = anltk::YEH;
		constants_m.attr("ALEF_WASLA")       = anltk::ALEF_WASLA;
		constants_m.attr("PEH")              = anltk::PEH;
		constants_m.attr("TCHEH")            = anltk::TCHEH;
		constants_m.attr("VEH")              = anltk::VEH;
		constants_m.attr("GAF")              = anltk::GAF;
		constants_m.attr("TATWEEL")          = anltk::TATWEEL;
		constants_m.attr("FATHATAN")         = anltk::FATHATAN;
		constants_m.attr("DAMMATAN")         = anltk::DAMMATAN;
		constants_m.attr("KASRATAN")         = anltk::KASRATAN;
		constants_m.attr("FATHA")            = anltk::FATHA;
		constants_m.attr("DAMMA")            = anltk::DAMMA;
		constants_m.attr("KASRA")            = anltk::KASRA;
		constants_m.attr("SHADDA")           = anltk::SHADDA;
		constants_m.attr("SUKUN")            = anltk::SUKUN;
		constants_m.attr("FASLA")            = anltk::FASLA;
		constants_m.attr("QUESTION_MARK")    = anltk::QUESTION_MARK;
		constants_m.attr("FASLA_MANKOOTA")   = anltk::FASLA_MANKOOTA;
		constants_m.attr("NOKTATAN")         = anltk::NOKTATAN;
		constants_m.attr("NESBA")            = anltk::NESBA;
		constants_m.attr("TA3AJJOB")         = anltk::TA3AJJOB;
		constants_m.attr("KAWS_MAFTOOH")     = anltk::KAWS_MAFTOOH;
		constants_m.attr("KAWS_MAKFOOL")     = anltk::KAWS_MAKFOOL;
		constants_m.attr("DARB")             = anltk::DARB;
		constants_m.attr("JAM3")             = anltk::JAM3;
		constants_m.attr("KESMA")            = anltk::KESMA;
		constants_m.attr("TAR7")             = anltk::TAR7;
		constants_m.attr("YOSAWI")           = anltk::YOSAWI;
		constants_m.attr("NOQTA")            = anltk::NOQTA;
		constants_m.attr("SEFR")             = anltk::SEFR;
		constants_m.attr("WAHED")            = anltk::WAHED;
		constants_m.attr("ETHNAN")           = anltk::ETHNAN;
		constants_m.attr("THALATHA")         = anltk::THALATHA;
		constants_m.attr("ARBA3A")           = anltk::ARBA3A;
		constants_m.attr("KHAMSA")           = anltk::KHAMSA;
		constants_m.attr("SETTA")            = anltk::SETTA;
		constants_m.attr("SAB3A")            = anltk::SAB3A;
		constants_m.attr("THAMANEYA")        = anltk::THAMANEYA;
		constants_m.attr("TES3A")            = anltk::TES3A;
		constants_m.attr("SMALL_ALEF")       = anltk::SMALL_ALEF;
		constants_m.attr("SMALL_WAW")        = anltk::SMALL_WAW;
		constants_m.attr("SMALL_YEH")        = anltk::SMALL_YEH;

		constants_m.attr("HARAKAT")  = anltk::tashkeel_list_;
		constants_m.attr("ARQAM")    = anltk::arqam_;
		constants_m.attr("ALPHABET") = anltk::alphabet_;
		constants_m.attr("QAMARI")   = anltk::qamari_;
		constants_m.attr("SHAMSI")   = anltk::shmasi_;
		// extern const std::array<char_t, 9> tashkeel_list_;
		// extern const std::array<char_t, 3> small_list_;
		// extern const std::array<char_t, 10> digits_;
	}
}
