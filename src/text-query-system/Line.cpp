// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"


Line::Line(const string& line) : line_{line}
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	//------------------------------------
	//5.2.2
        transform(line_.begin(), line_.end(), line_.begin(), ::tolower);
}

bool Line::contains(const Word& search_word) const
{
    //------------------------------------
    //5.2.3
        if (search_word.word_.size() < 3)
        return false;
	//------------------------------------
	//5.2.2
    if (line_.find(search_word.word_) != string::npos)
        return true;
    else
        return false;
}
