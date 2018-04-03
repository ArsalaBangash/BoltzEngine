//
// Created by KyoKeun Park on 2018-04-02.
//

#ifndef ENGINE_BINARYGENERATOR_HPP
#define ENGINE_BINARYGENERATOR_HPP

#include <utility>
#include <string>
#include "Enums.h"

class BinaryChallenge
{
    BinaryChallenge(std::string, std::string, bool);
    static std::pair<std::string, std::string> getBiDecPair(Level);

public:
    std::string decimal;
    std::string binary;
    bool binaryToDec = false;

    static BinaryChallenge *generateBinaryQuestion(Level);
};

#endif //ENGINE_BINARYGENERATOR_HPP
