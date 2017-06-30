//
//  main.cpp
//  Problem1
//
//      If we list all the natural numbers below 10 that are multiples of 3 or
//      5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//      Find the sum of all the multiples of 3 or 5 below 1000.
//
//  Copyright © 2017 castellanese. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "ProblemUtilities.h"

std::vector<size_t> GenerateMultiplesOf(size_t const multiplier,
                                        size_t const largestMultiplier)
{
    std::vector<size_t> mults(largestMultiplier);
    
    size_t increment{ 1 };
    
    std::generate(mults.begin(),
                  mults.end(),
                  [&multiplier, &increment]
                  { return multiplier * increment++; });
    
    return mults;
}

template<typename Numeric>
inline std::vector<Numeric> ComputeUnion(std::vector<Numeric> const v1,
                                         std::vector<Numeric> const v2)
{
    std::vector<Numeric> result;
    std::set_union(v1.begin(),
                   v1.end(),
                   v2.begin(),
                   v2.end(),
                   std::back_inserter(result));
    return result;
}

int main()
{
    size_t const upperLimit = 1000 - 1;
    size_t const maxMultOfThree = upperLimit / 3;
    size_t const maxMultOfFive = upperLimit / 5;
    
    auto const multsOfThree = GenerateMultiplesOf(3, maxMultOfThree);
    auto const multsOfFive  = GenerateMultiplesOf(5, maxMultOfFive);
    
    auto const multsOfThreeOrFive = ComputeUnion(multsOfThree, multsOfFive);
    
    std::cout <<
    "Sum of all multiples of three or five less than 1000 is "
    << std::accumulate(multsOfThreeOrFive.begin(), multsOfThreeOrFive.end(), 0)
    << std::endl;
    
    return 0;
}
