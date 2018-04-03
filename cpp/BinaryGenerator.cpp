//
// Created by KyoKeun Park on 2018-04-02.
//

#include <math.h>
#include <iostream>
#include "BinaryGenerator.hpp"
#include "EngineUtils.hpp"

BinaryChallenge *BinaryChallenge::generateBinaryQuestion(Level level)
{
    std::pair<std::string, std::string> biDecPair = getBiDecPair(level);
    if (random(0, 1) > 0.5)
        return new BinaryChallenge(biDecPair.first, biDecPair.second, true);
    else
        return new BinaryChallenge(biDecPair.first, biDecPair.second, false);
}

std::pair<std::string, std::string> BinaryChallenge::getBiDecPair(Level level)
{
    int decimal = 0;
    int maxNum = 0;
    switch (level)
    {
        case Level::Basic :
            maxNum = 64;
            break;
        case Level::Advanced :
            maxNum = 256;
            break;
        default:
            maxNum = 128;
            break;
    }
    decimal = generatePositiveRandom(maxNum) + 1;
    std::string binary = std::string("0");
    for (int i = (int) log2(maxNum); i >= 0; i--)
        binary.append(std::to_string((decimal >> i) & 1));
    return std::pair<std::string, std::string>(std::to_string(decimal), binary);
}

BinaryChallenge::BinaryChallenge(std::string decimal, std::string binary, bool binaryToDec)
{
    this->decimal = decimal;
    this->binary = binary;
    this->binaryToDec = binaryToDec;
}
