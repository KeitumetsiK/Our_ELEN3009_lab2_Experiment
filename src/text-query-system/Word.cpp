// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <algorithm>
#include <string>

Word::Word(const string& word): word_{word}
{
	// prevents case sensitivity by making all characters in word_ lower case
	transform(word_.begin(), word_.end(), word_.begin(), ::tolower);

    // prevents punctuation sensitivity
	punctuationIgnore(word_);

	// throws WordContainsSpace if word has space
	checkSpace(word_);

	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (word_ == rhs.word_)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
    if (word_.size() < 3)
	    return false;
	else
        return true;
}

void Word::punctuationIgnore(string& word)
{
    for(int i = 0; i <word.size(); i++)
    {
       if (word[i] == ' ') throw WordContainsSpace{};

       if (word[i] == '~' || word[i] == '`'|| word[i] == '!'|| word[i] == '@'|| word[i] == '#'|| word[i] == '$'|| word[i] == '%'|| word[i] == '^'|| word[i] == '&'|| word[i] == '*'|| word[i] == '('|| word[i] == ')'|| word[i] == '-'|| word[i] == '_'|| word[i] == '+'|| word[i] == '='|| word[i] == '{'|| word[i] == '}'|| word[i] == '['|| word[i] == ']'|| word[i] == '\\'|| word[i] == '|'|| word[i] == ';'|| word[i] == ':'|| word[i] == '\''|| word[i] == '<'|| word[i] == '>'|| word[i] == '?'|| word[i] == ','|| word[i] == '.'|| word[i] == '/'|| word[i] == '"')
       {
           word.erase(i--,1);
       }
    }
}

void Word::checkSpace(string& word)
{
    for(int i = 0; i <word.size(); i++)
    {
       if (word[i] == ' ') throw WordContainsSpace{};
    }
}
