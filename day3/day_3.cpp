//
// Created by danie on 04/12/2024.
//

#include "day_3.h"

int day_3() {
    std::string currentLine;
    std::ifstream inputFile;

    inputFile.open("C:/Users/danie/CLionProjects/advent-of-code-2024/day3/input.txt");

    std::regex regexPattern(R"(mul\((\d+),(\d+)\))");
    int runningCount = 0;

    while (getline(inputFile, currentLine)) {
        std::smatch match;


        while (std::regex_search(currentLine, match, regexPattern)) {
            if (match.size() == 3) {
                int n1 = std::stoi(match[1].str());
                int n2 = std::stoi(match[2].str());


                runningCount += n1 * n2;
            }


            currentLine = match.suffix().str();
        }
    }

    return runningCount;
}




