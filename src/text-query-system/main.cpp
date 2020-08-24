// main.cpp
// Main for TextQueryApp


#include "Word.h"
#include "Paragraph.h"
#include "Line.h"
#include "FileReader.h"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    auto paragraph = Paragraph{};

    string fileName = "", word = "";
    cout << "Please enter file name: ";
    cin >> fileName;
    cout << endl;

    auto filereader = FileReader{fileName};
    filereader.readFileInto(paragraph);

    start:
    cout << "Please enter a word to search for or ""."" to quit: ";
    cin >> word;
    cout << endl;

    if(word == ".")
    {
        return 0;
    }

    auto[found, line_numbers] = paragraph.contains(Word{word});

    if (!found){cout << "Word not found" << endl;}

    else
    {
        cout << "Word found: ";

        for (int i = 0; i < line_numbers.size(); i++)
        {
            if (i==0){cout << "Line " << line_numbers[i] << endl;}
            else{cout << "            Line " << line_numbers[i] << endl;}
        }
    }
    cout << endl;

    goto start;

    return 0;
}
