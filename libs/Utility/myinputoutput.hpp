#ifndef MYINPUTOUTPUT_HPP_
#define MYINPUTOUTPUT_HPP_

#include <iostream>
#include <iomanip>
#include <string>

//Converts a string to lower case
inline void to_lower(std::string& s) 
{
    for(auto i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }
}

//Converts a string to upper case
inline void to_upper(std::string& s)
{
    for(auto i = 0; i < s.size(); i++){
        if(isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
        }
    }
}

//Checks a string if it is an integer
inline bool is_integer(const std::string& s)
{
    for(auto i = 0; i < s.size(); ++i)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

//Prints argument s in the center specified by maxL and boarder
inline void print(const std::string s,int maxL, char boarder)
{
    std::cout << "#" << std::right << std::setw((maxL+s.size())/2) << s;
    //Checks if string is odd or even
    if(s.size()%2!=0)
    {
        std::cout << std::right << std::setw((maxL-s.size())/2+2) << '#';
    }
    else
    {
        std::cout << std::right << std::setw((maxL-s.size())/2+1) << '#';
    }
    std::cout << std::endl;
}

#endif