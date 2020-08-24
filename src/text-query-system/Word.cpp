// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <algorithm>

Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};
	//--------------------------------------
	//5.1.1
	if (!word_.empty()) {transform(word_.begin(),word_.end(), word_.begin(), ::tolower);}
    //--------------------------------------
    //5.1.2 && 5.1.3
    /*
    I did 5.1.2 first like this
    	//--------------------------------------
	//5.1.2
    if (!word_.empty()) {word_.erase(remove_if(word_.begin (), word_.end (), ::ispunct), word_.end ());}
    then i did 5.1.3 as below so as to make both test pass, i do not know if its correct but it is how i did it
    */

    if (!word_.empty())
    {   int i = 0;
        int valid = 0;
        while (i < word_.size())
        {
            if (ispunct(word_[i]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
            i++;
        }
        //--------------------------------------
        //5.1.2
        if (valid == 0){word_.erase(remove_if(word_.begin (), word_.end (), ::ispunct), word_.end ());}
        //--------------------------------------
        //5.1.3
        if (valid == 1)
        {
            throw WordContainsNoLetters {};
        }

    }

    //---------------------------------------------------
    //5.1.4

    if (!word_.empty())
    {
        string::size_type i = 0;
        while (i < word_.size())
        {
            if (word_[i] == ' ')
            {
                throw WordContainsSpace {};
            }
            i++;
        }
    }

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
    //----------------------------------------------
    //5.1.5
        string::size_type min_queryable_size = 3;

        if(word_.size() < min_queryable_size)
        {
            return false;
        }
        else
        {
            return true;
        }

}




