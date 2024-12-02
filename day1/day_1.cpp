#include "day_1.h"


int day_1() {


    std::ifstream fileInput;

    fileInput.open("C:/Users/danie/CLionProjects/advent-of-code-2024/day1/input.txt");

    if (fileInput.fail()) {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }

    std::vector <int> numbers1;
    std::vector <int> numbers2;

    std::string sCurrentLine;

    while (std::getline(fileInput, sCurrentLine)) {
        std::istringstream lineSteam(sCurrentLine);

        int number1;
        int number2;

        lineSteam >> number1;
        lineSteam >> number2;
        numbers1.push_back(number1);
        numbers2.push_back(number2);
    }

    std::ranges::sort(numbers1);
    std::ranges::sort(numbers2);


    int runningCount = 0;

    for (int i = 0; i <= numbers1.size(); i++) {
        if (numbers1[i] > numbers2[i]) {
            runningCount += (numbers1[i] - numbers2[i]);
        } else if (numbers1[i] < numbers2[i]) {
            runningCount += (numbers2[i] - numbers1[i]);
        }
    }

    int runningCountPartB = 0;


    // used for tracking the index on the inner loop to avoid looping over numbers that are known to be smaller than
    // the outer loop.

    int indexCount = 0;

    for (int i : numbers1) {
        int nAppeared = 0;

        for (int j : numbers2) {

            if (i == j) {
                nAppeared += 1;

            }
        }

        runningCountPartB += (i * nAppeared);
    }

    return runningCountPartB;
}
