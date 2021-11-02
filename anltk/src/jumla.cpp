
#include <anltk/anltk.hpp>
#include <ostream>
#include <utf8.h>

namespace anltk
{

Harf::Harf(char32_t c) : m_c(c)
{
}

Harf Harf::create(char32_t c)
{
	return Harf(c);
}
anltk::char_t Harf::c()
{
	return m_c;
}
std::ostream& operator<<(std::ostream& os, const Harf& h)
{
	os << h.to_string();
	return os;
}

std::string Harf::to_string() const
{
	return utf8::utf32to8(std::u32string{ m_c });
}

Harf* Harf::next()
{
	return m_next;
}
Harf* Harf::prev()
{
	return m_prev;
}

Harf* Harf::next() const
{
	return m_next;
}
Harf* Harf::prev() const
{
	return m_prev;
}

void Harf::set_next(Harf* next)
{
	m_next = next;
}
void Harf::set_prev(Harf* prev)
{
	m_prev = prev;
}
Kalima* Harf::kalima()
{
	return m_kalima;
}
void Harf::set_kalima(Kalima* kalima)
{
	m_kalima = kalima;
}

bool Harf::operator==(std::string_view other) const noexcept
{
	return this->to_string() == other;
}
bool Harf::operator==(anltk::char_t c) const noexcept
{
	return m_c == c;
}

Kalima::Kalima(anltk::string_view_t text)
{
	m_text     = text.data();
	auto start = text.begin();
	auto end   = text.end();
	while (start < end)
	{
		anltk::char_t next = utf8::next(start, end);

		auto new_harf = Harf(next);

		m_huroof.push_back(new_harf);
	}

	Harf* prev = nullptr;
	for (Harf& harf : m_huroof)
	{
		harf.set_prev(prev);
		if (prev)
		{
			prev->set_next(&harf);
		}
		prev = &harf;
	}
}

Kalima::iterator_t Kalima::begin()
{
	return m_huroof.begin();
}
Kalima::iterator_t Kalima::end()
{
	return m_huroof.end();
}

Kalima::const_iterator_t Kalima::begin() const
{
	return m_huroof.cbegin();
}
Kalima::const_iterator_t Kalima::end() const
{
	return m_huroof.cend();
}

Harf* Kalima::first()
{
	if (m_huroof.empty())
	{
		return nullptr;
	}
	return &m_huroof.front();
}

Harf* Kalima::last()
{
	if (m_huroof.empty())
	{
		return nullptr;
	}
	return &m_huroof.back();
}

Kalima* Kalima::next()
{
	return m_next;
}
Kalima* Kalima::prev()
{
	return m_prev;
}

void Kalima::set_next(Kalima* next)
{
	m_next = next;
}

void Kalima::set_prev(Kalima* prev)
{
	m_prev = prev;
}

std::string Kalima::to_string() const
{
	return m_text;
}

size_t Kalima::size() const
{
	return m_huroof.size();
}

bool Kalima::operator==(std::string_view str) const noexcept
{
	return m_text == str;
}

std::ostream& operator<<(std::ostream& os, const Kalima& kalima)
{
	for (const Harf& c : kalima)
	{
		os << c;
	}
	return os;
}

Jumla::Jumla(anltk::string_view_t text)
{
	m_text                          = text.data();
	std::vector<std::string> tokens = anltk::split(text);

	for (const auto& token : tokens)
	{
		m_kalimat.push_back(Kalima(token));

		Kalima& kalima = m_kalimat.back();
		for (auto& harf : kalima)
		{
			harf.set_kalima(&kalima);
		}
	}

	Kalima* prev = nullptr;
	for (Kalima& kalima : m_kalimat)
	{
		kalima.set_prev(prev);
		if (prev)
		{
			prev->set_next(&kalima);
		}
		prev = &kalima;
	}
}

Kalima* Jumla::first()
{
	if (m_kalimat.empty())
	{
		return nullptr;
	}
	return &m_kalimat.front();
}

Kalima* Jumla::last()
{
	if (m_kalimat.empty())
	{
		return nullptr;
	}
	return &m_kalimat.back();
}

Jumla::iterator_t Jumla::begin()
{
	return m_kalimat.begin();
}
Jumla::iterator_t Jumla::end()
{
	return m_kalimat.end();
}

Jumla::const_iterator_t Jumla::begin() const
{
	return m_kalimat.cbegin();
}
Jumla::const_iterator_t Jumla::end() const
{
	return m_kalimat.cend();
}

size_t Jumla::size() const
{
	return m_kalimat.size();
}
std::string Jumla::to_string() const
{
	return m_text;
}

bool Jumla::operator==(std::string_view str) const noexcept
{
	return m_text == str;
}

std::ostream& operator<<(std::ostream& os, const Jumla& jumla)
{
	for (const Kalima& k : jumla)
	{
		os << k << " ";
	}
	return os;
}

} // namespace anltk
