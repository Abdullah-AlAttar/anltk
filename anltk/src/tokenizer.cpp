#include <anltk/anltk.hpp>

namespace anltk
{

template <typename Iter, typename F>
string_t parse_sequence(char_t& next, Iter& start, Iter end, bool& done, F&& predicate)
{
    string_t res;
    utf8::append(next, res);
    next = utf8::next(start, end);
    while (true)
    {
        if (!predicate(next))
        {
            done = (start == end);
            break;
        }
        utf8::append(next, res);
        if (start == end)
        {
            break;
        }
        next = utf8::next(start, end);
    }
    return res;
}

const std::vector<const char*>& Tokenizer::tokenize_words(string_view_t input)
{

    if(input.empty())
    {
        return result_;
    }

    auto start = input.begin();
    auto end   = input.end();
    
    char_t next = utf8::next(start, end);
    bool done   = false;

    while (start != end)
    {

        if (isspace(next))
        {
            next = utf8::next(start, end);
            continue;
        }

        if (is_arabic_alpha(next) || is_tashkeel_c(next))
        {
            this->holder_.push_back(parse_sequence(next, start, end, done,
                                                   [](char_t c) { return is_arabic_alpha(c) || is_tashkeel_c(c); }));
        }
        else
        {
            this->holder_.push_back(parse_sequence(next, start, end, done,
                                                   [](char_t c)
                                                   { return !is_arabic_alpha(c) && !isspace(c); }));
        }
        // To handle last character, if it didn't belong to the previous sequence eg : "بسم."
        if (done)
        {
            string_t last;
            utf8::append(next, last);
            this->holder_.push_back(std::move(last));
        }
    }

    result_.reserve(holder_.size());

    for (const auto& token : this->holder_)
    {
        result_.push_back(token.c_str());
    }

    return result_;
}

} // namespace anltk
