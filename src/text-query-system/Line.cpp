// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <string>
#include <algorithm>

Line::Line(const string& line):line_{line}
{
    // Hint: some of string's member functions might come in handy here
    // for extracting words.
    transform(line_.begin(), line_.end(), line_.begin(), ::tolower);

}

bool Line::contains(const Word& search_word) const
{
    if (search_word.word_.size() < 3)
        return false;

    size_t found = line_.find(search_word.word_);

    if (found != string::npos)
        return true;
    else
        return false;
}
