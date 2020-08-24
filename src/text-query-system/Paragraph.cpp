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
    if (paragraph_.empty()){

       return {false, vector<int>{}};
    }

    vector<int> containedLineNo = {};

    for(int i = 0; i < paragraph_.size(); i++)
    {
        size_t found = paragraph_[i].find(search_word.word_);

        if (found != string::npos)
        {
            containedLineNo.push_back(i+1);
        }
    }
    if(containedLineNo.empty())
    {
        return {false, vector<int>{}};
    }

    else
    {
       return {true, containedLineNo};
    }
}
