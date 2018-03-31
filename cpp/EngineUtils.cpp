//
//  EngineUtils.cpp
//  Boltz
//
//  Created by KyoKeun Park on 2018-03-19.
//  Copyright © 2018 KyoKeun Park. All rights reserved.
//

#include "EngineUtils.hpp"

double random(int min, int max)
{
    std::default_random_engine gen ((unsigned int)std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

int generateNonZero(int absoluteRange)
{
    int num = (int) random(-absoluteRange, absoluteRange);
    if (num == 0)
        num++;
    return num;
}

int generatePositiveRandom(int min, int max)
{
    return (int) random(min, max);
}

int generatePositiveRandom(int max)
{
    return (int) random(1, max);
}

int generatePosNegRandom(int range)
{
    return (int) random(-range, range);
}
