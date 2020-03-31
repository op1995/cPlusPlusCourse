//based on header file shown in the lecture

#pragma once

#include <string>

using namespace std;

namespace phonetic {
    string find(string text, string word);
    bool letter_match (char original, char current);
    bool replacable_letters(char original, char current); 
}