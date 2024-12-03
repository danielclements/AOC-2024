

#include "day_2.h"


int day_2() {

    std::ifstream inputFile;
    inputFile.open("C:/Users/danie/CLionProjects/advent-of-code-2024/day2/input.txt");

    if (inputFile.fail()) {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }

    std::string currentLine;

    int safeReports = 0;

    while (std::getline(inputFile, currentLine)) {
        std::istringstream lineStream(currentLine);
        std::vector<int> currentReport;
        int number;
        bool isSafe = true;

        while (lineStream >> number) {
                currentReport.push_back(number);

        }


        if (!std::ranges::is_sorted(currentReport, std::greater<>()) &&
            !std::ranges::is_sorted(currentReport)) {
            goto loopEnd;
        }

        for (int i = 0; i < currentReport.size() - 1 ; i++) {
            int currentComparrison = std::abs(currentReport[i] - currentReport[i + 1]);
            if (currentComparrison > 3 || currentComparrison == 0) {
                goto loopEnd;
            }

        }

            safeReports += 1;
            loopEnd:
    }

    return safeReports;

}