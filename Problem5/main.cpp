//
//  main.cpp
//  Problem5
//
//      2520 is the smallest number that can be divided by each of the numbers
//      from 1 to 10 without any remainder.
//
//      What is the smallest positive number that is evenly divisible by all of
//      the numbers from 1 to 20?
//
//  Copyright © 2017 castellanese. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

template<typename Numeric>
Numeric gcd(Numeric a, Numeric b)
{
    Numeric tmp = 0;
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

template<typename Numeric>
Numeric lcm(Numeric a, Numeric b)
{
    auto product = a * b;
    return (product < 0 ? product * -1: product) / gcd(a, b);
}

int main()
{
    std::vector<size_t> elevenThroughTwenty{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    std::cout << std::accumulate(elevenThroughTwenty.begin(),
                                 elevenThroughTwenty.end(),
                                 1,
                                 lcm<size_t>)
    << " is the smallest positive number that is evenly divisible by 1 through 20."
    << std::endl;
    
    return 0;
}
