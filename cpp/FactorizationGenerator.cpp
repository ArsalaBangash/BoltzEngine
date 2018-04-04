//
// Created by KyoKeun Park on 2018-04-03.
//

#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <regex>
#include <string>
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
    std::vector<std::string> stringArr;

    boost::replace_all(infix, "-", "+-");
    boost::split(stringArr, infix, boost::is_any_of("+"), boost::token_compress_on);
    boost::regex re("(x\\^2)|[x*]");

    std::vector<std::string> regParsed;
    std::vector<int> intArr;
    for (int i = 0; i < stringArr.size(); i++) {
        regParsed.emplace_back(boost::regex_replace(stringArr[i], re, ""));
        if (!regParsed[i].empty())
            intArr.emplace_back(std::stoi(regParsed[i]));
        else
            intArr.emplace_back(1);
    }
    return intArr;
}