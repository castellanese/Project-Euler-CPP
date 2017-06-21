//
//  main.cpp
//  Problem3
//
//      The prime factors of 13195 are 5, 7, 13 and 29.
//
//      What is the largest prime factor of the number 600851475143?
//
//  Copyright © 2017 castellanese. All rights reserved.
//

#include <iostream>

bool isPrime(size_t const value)
{
    for (auto i = 2; i <= (value / 2); ++i)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}

void factor(size_t const value, size_t & largestPrimeFactor)
{
    for (auto i = 2; i <= (value / 2); i++)
    {
        if (value % i == 0)
        {
            factor(value / i, largestPrimeFactor);
            
            if (i > largestPrimeFactor && isPrime(i))
            {
                largestPrimeFactor = i;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    size_t const numberToBeFactored{600851475143};
    size_t largestFactor{1};
    
    factor(numberToBeFactored, largestFactor);
    
    std::cout << largestFactor << std::endl;
    return 0;
}
