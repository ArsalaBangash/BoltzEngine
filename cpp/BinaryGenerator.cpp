//
// Created by KyoKeun Park on 2018-04-02.
//

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
    int decimal;
    switch (level)
    {
        case Level::Basic :
            decimal = generatePositiveRandom(64) + 1;
        case Level::Advanced :
            decimal = generatePositiveRandom(256) + 1;
        default:
            decimal = generatePositiveRandom(128) + 1;
    }
    std::string binary = std::string("0").append(std::to_string(decimal));
    return std::pair<std::string, std::string>(std::to_string(decimal), binary);
}

BinaryChallenge::BinaryChallenge(std::string decimal, std::string binary, bool binaryToDec)
{
    this->decimal = decimal;
    this->binary = binary;
    this->binaryToDec = binaryToDec;
}
