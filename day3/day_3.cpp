//
// Created by danie on 04/12/2024.
//

#include "day_3.h"

#include <string.h>

int day_3() {
    std::string currentLine;
    std::ifstream inputFile;
    inputFile.open("C:/Users/danie/CLionProjects/advent-of-code-2024/day3/input.txt");

    std::regex regexPattern(R"(mul\((\d+,\d+)\))");  //Regex expression to match to mul(0-1000,0-1000) mul\\((?=)[1-9].?.?,[0-9].?.??(?!= or ?<!)\\)
    int runningCount = 0;



    while (getline(inputFile, currentLine)) {
        std::string linee;
        std::istringstream lineStream(currentLine);



        std::vector<std::string> matchBucket;

        while (lineStream >> linee) {
            matchBucket = std::vector<std::string>{
                std::sregex_token_iterator{linee.begin(), linee.end(), regexPattern},
                std::sregex_token_iterator{}};
        }

        int n1 = 0;
        int n2 = 0;

        for (std::string i : matchBucket) {
            for (int j = 0; j < i.size(); j++) {
                auto debug = i[j];
                if (strcmp(&debug,"(")) {
                    std::cout << i[j] << std::endl;
                }
            }
        }

        }




        return runningCount;
        }

        // https://en.cppreference.com/w/cpp/regex/regex_iterator
        // https://en.cppreference.com/w/cpp/regex





