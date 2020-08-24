// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
    paragraph_.push_back(line.line_);
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{

    string store_line;
    vector<int> store_line_number = {};

    if (paragraph_.empty()){
       return {false, vector<int>{}};
    }

    for(int ind = 0; ind < paragraph_.size();ind++)
    {
    store_line = paragraph_[ind];
    if (store_line.find(search_word.word_) != string::npos)
    {
        store_line_number.push_back(ind+1);
    }
    }
    if (store_line_number.empty())
    {
        return {false, vector<int>{}};
    }
    else
    {
        return {true, store_line_number};
    }
}
