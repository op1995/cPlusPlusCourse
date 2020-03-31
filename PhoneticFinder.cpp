//used geeksforgeeks to learn how to use istringstream

#include "PhoneticFinder.hpp"
// #define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;


namespace phonetic {
    string find(string text, string word){
        // cout << "looking for the word " + word +"\n";
    	if (word.size()==0) throw invalid_argument("Inserted word is of length 0!");
        if (text.size()==0) throw invalid_argument("Inserted text is of length 0!");

        std::istringstream iss(text);

        do{
            string current_word;
            iss >> current_word;
            if(current_word.size()==word.size()){ //only if current_word is of same length as asked for word, it could be an answer
                // cout << "testing the word " + current_word +"\n";
                if(current_word.compare(word)==0) {
                    // cout << "@@@Returned using simple compare function\n";
                    return current_word;
                }
                bool flag = true;
                for(std::string::size_type i = 0; i < current_word.size() && flag; ++i) { //checking each letter
                    // cout << "i = ";
                    // cout << i;
                    // cout << "\ncurrent_word.size() = ";
                    // cout << current_word.size();
                    // cout << "\ncomparing ";
                    // cout << word[i];
                    // cout << " to ";
                    // cout << current_word[i];
                    // cout << "\n";

                    if(current_word.compare("is")==0){
                        string comp = "comparing the letters ";
                        comp = comp + word[i] + " and " + current_word[i] + "\n";
                        cout << comp;
                    }

                    if (!(letter_match(word[i], current_word[i]))) {
                        // string failed = "the letters that didn't match were at place ";
                        // failed = failed + to_string(i);
                        // cout << "the letters that didn't match were at place " + (int)i;
                        // cout << failed;
                        // cout << " and " + current_word[i];
                        if(current_word.compare("is")==0) cout << "flag is now false!\n";
                        flag = false;
                    }// end if letters match
                    if(current_word.compare("is")==0) cout << "true!\n";
                }// end for loop
                if (flag) {
                    // cout << "HERE123";
                    return current_word; //reaching here with flag still having true value means all letters matched according to rules.
                }// end if flag
                
            } //end if word sizes equal
        }while(iss);

        // if (true) throw invalid_argument("Word was not found in text!");
        throw invalid_argument("Word was not found in text!");
        // else return "";

        // return "!!!";


        // cout << "Grade: 56" << endl;
        // return "happy";
    }

    bool letter_match (char original, char current){
        // first change capital to lower case, for both letters. To make sure of working on the same thing.
        // no need to check for ascii values outside of the abc values, as the assignment stated input will only contain abc ascii values.
        if ((int)original>64 && (int)original<91){
            original = original + 32;
        }
        if ((int)current>64 && (int)current<91){
            current = current + 32;
        }

        if(original == current) return true;
        
        if (replacable_letters(original, current)) return true; //if the letters are replaceable, return true

        return false; //if you got here, all failed. Return false.



    }

    bool replacable_letters(char original, char current){
        // string comp = "comparing the letters ";
        // comp = comp + original + " and " + current + "\n";
        // cout << comp;

        switch(original)
        {
            case 'v':
                if(current=='w')return true;
            case 'w':
                if(current=='v')return true;
            case 'b':
                if(current=='f')return true;
                if(current=='p')return true;
            case 'f':
                if(current=='b')return true;
                if(current=='p')return true;
            case 'p':
                if(current=='b')return true;
                if(current=='f')return true;
            case 'g':
                if(current=='j')return true;
            case 'j':
                if(current=='g')return true;
            case 'c':
                if(current=='k')return true;
                if(current=='q')return true;
            case 'k':
                if(current=='c')return true;
                if(current=='q')return true;
            case 'q':
                if(current=='c')return true;
                if(current=='k')return true;
            case 's':
                if(current=='z')return true;
            case 'z':
                if(current=='s')return true;
            case 'd':
                if(current=='t')return true;
            case 't':
                if(current=='d')return true;
            case 'o':
                if(current=='u')return true;
            case 'u':
                if(current=='o')return true;
            case 'i':
                if(current=='y')return true;
            case 'y':
                if(current=='i')return true;
            default:
                return false;
        }//end switch
    }//end replacable letters function



}