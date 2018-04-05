//
// Created by KyoKeun Park on 2018-04-03.
//

#include <regex>
#include <string>
#include <sstream>
#include "FactorizationGenerator.hpp"
#include "EngineUtils.hpp"

void FactorizationGenerator::setMax(Level level) {
    switch (level) {
        case Basic :
            xCoeffMax = 1;
            constMax = 5;
            break;
        case Normal :
            xCoeffMax = 2;
            constMax = 10;
            break;
        case Advanced :
            xCoeffMax = 3;
            constMax = 10;
            break;
    }
}

FactorizationGenerator::FactorParams FactorizationGenerator::generateFactorParams(Level level) {
    setMax(level);
    FactorizationGenerator::FactorParams fp{};
    fp.xCoeff1 = generatePositiveRandom(xCoeffMax);
    fp.xCoeff2 = generatePositiveRandom(xCoeffMax);
    fp.const1 = generatePositiveRandom(constMax);
    fp.const2 = generatePositiveRandom(constMax);
    return fp;
}

std::vector<int> FactorizationGenerator::getExpandedParams(std::string infix) {

    std::string replaced = std::regex_replace(infix, std::regex("-"), "+-");
    replaced = std::regex_replace(replaced, std::regex(" "), "");
    std::vector<std::string> stringArr = split(replaced, '+');

    std::vector<std::string> regParsed;
    std::vector<int> intArr;
    for (int i = 0; i < stringArr.size(); i++) {
        regParsed.emplace_back(std::regex_replace(stringArr[i], std::regex("(x\\^2)|[x*]"), ""));
        if (!regParsed[i].empty())
            intArr.emplace_back(std::stoi(regParsed[i]));
        else
            intArr.emplace_back(1);
    }
    return intArr;
}