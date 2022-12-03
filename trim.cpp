#include "includes.h"
#include "trim.h"

// taken from: https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
// i figured this would be rather useful, so I put it into a seperate cpp & header file

// trim from start (in place)
void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
std::string ltrimCopy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string rtrimCopy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string trimCopy(std::string s) {
    trim(s);
    return s;
}