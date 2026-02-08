#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib> // use for clear screen in the console 
#include "utils.h"


std::string trim(const std::string& str) 
{
    std::string s = str;

    // leading spaces
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char c){ return !std::isspace(c); }));

    // trailing spaces
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char c){ return !std::isspace(c); }).base(), s.end());

    return s;
}


std::string toTitleCase(std::string str) 
{
    bool newWord = true;
    for (char &c : str) 
    {
        if (isspace(c))
        {
            newWord = true;

        }
        else
        {
            if (newWord) 
            {
                c = toupper(c);
                newWord = false;

            }
            else
            {
                c = tolower(c);
            }
        }
    }
    return str;
}


void clearScreen() 
{
    system("cls");
}