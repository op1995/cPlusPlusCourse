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
        if (word.find(" ") != std::string::npos) {
            throw invalid_argument("word searched for can't contain space!");
        }

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

                    // if(current_word.compare("is")==0){
                    // string comp = "comparing the letters ";
                    // comp = comp + word[i] + " and " + current_word[i] + "\n";
                    // cout << comp;
                    // }

                    if (!(letter_match(word[i], current_word[i]))) {
                        // string failed = "the letters that didn't match were at place ";
                        // failed = failed + to_string(i) + "\n";
                        // cout << failed;
                        // cout << " and " + current_word[i];
                        flag = false;
                    }// end if letters match
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

        // string stg = "original is ";
        // stg = stg + original + " and current is " + current +"\n";
        // cout << stg;

        if(original == current) {
            // cout << "returning TRUE from simple compare\n";
            return true;
        }
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
                // cout << "\n1\n";
                if(current=='w')return true;
                else return false;
            case 'w':
                // cout << "\n2\n";
                if(current=='v')return true;
                else return false;
            case 'b':
                // cout << "\n3\n";
                if(current=='f')return true;
                if(current=='p')return true;
                else return false;
            case 'f':
                // cout << "\n4\n";
                if(current=='b')return true;
                if(current=='p')return true;
                else return false;
            case 'p':
                // cout << "\n5\n";
                if(current=='b')return true;
                if(current=='f')return true;
                else return false;
            case 'g':
                // cout << "\n6\n";
                if(current=='j')return true;
                else return false;
            case 'j':
                // cout << "\n7\n";
                if(current=='g')return true;
                else return false;
            case 'c':
                // cout << "\n8\n";
                if(current=='k')return true;
                if(current=='q')return true;
                else return false;
            case 'k':
                // cout << "\n9\n";
                if(current=='c')return true;
                if(current=='q')return true;
                else return false;
            case 'q':
                // cout << "\n10\n";
                if(current=='c')return true;
                if(current=='k')return true;
                else return false;
            case 's':
                // cout << "\n11\n";
                if(current=='z')return true;
                else return false;
            case 'z':
                // cout << "\n12\n";
                if(current=='s')return true;
                else return false;
            case 'd':
                // cout << "\n13\n";
                if(current=='t')return true;
                else return false;
            case 't':
                // cout << "\n14\n";
                if(current=='d')return true;
                else return false;
            case 'o':
                // cout << "\n15\n";
                if(current=='u')return true;
                else return false;
            case 'u':
                // cout << "\n16\n";
                if(current=='o')return true;
                else return false;
            case 'i':
                // cout << "\n17\n";
                if(current=='y')return true;
                else return false;
            case 'y':
                // cout << "\n18\n";
                if(current=='i')return true;
                else return false;
            default:
                // cout << "\nDEFAULT\n";
                return false;
        }//end switch
        return false;
    }//end replacable letters function



}