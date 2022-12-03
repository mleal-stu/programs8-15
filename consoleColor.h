#pragma once

#include "includes.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <Windows.h>

// this code is exceptionally useful for console printing in C++, so I made a header file for it

void outputColoredText(std::string text, std::string color) {
#ifdef _WIN32 // code used for windows machines
    std::unordered_map<std::string, int> colorLookup = {
        {"black", 0},
        {"blue", 1},
        {"green", 2},
        {"cyan", 3},
        {"red", 4},
        {"purple", 5},
        {"yellow", 6},
        {"white", 7},
        {"error", 4},
        {"debug", 1}
    };
    // contains the windows color codes used by the console text attribute method

    try {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorLookup[color]);

        std::cout << text << std::endl;

        SetConsoleTextAttribute(hConsole, 15);
    }
    catch (...) {
        std::cout << "error writing colored text" << std::endl;
        std::cout << text << std::endl;
    }
    // std::cout << "DEBUG: " << color << " : " << colorLookup[color] << std::endl;

#else // code used for non-windows machines
    std::unordered_map<std::string, int> colorLookup = {
        {"black", 30},
        {"blue", 34},
        {"green", 32},
        {"cyan", 36},
        {"red", 31},
        {"purple", 35},
        {"yellow", 33},
        {"white", 37},
        {"error", 31},
        {"debug", 34}
    };
    // ASCI escape cdoes

std:cout << "\033[" + colorLookup[color] + "m" + text + "\033[0m" << std::endl;
   
#endif
    return;
}
// allow for printing of colored text (in partucular, used for errors)
// supports black, red, green, yellow, blue, purple, cyan, white
// inputting "error" or "debug" outputs red and blue text, respectively