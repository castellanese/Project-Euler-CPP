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
#include <functional>

template<typename Functor>
void CallFunctorIfValueHasFactor(size_t const value, Functor const f)
{
    bool stopSearching = true;
    
    for (auto currentFactor = 2; currentFactor <= (value / 2); ++currentFactor)
    {
        if (value % currentFactor == 0)
        {
            if (f(currentFactor) == stopSearching)
            {
                break;
            }
        }
    }
}


bool isPrime(size_t const value)
{
    bool isAPrime = true;
    
    CallFunctorIfValueHasFactor(value,
                                [&isAPrime] (size_t const)
                                { isAPrime = false; return true; });
    
    return isAPrime;
}

void factor(size_t const value, size_t & largestPrimeFactor)
{
    auto findLargestPrimeFactor = [&value, &largestPrimeFactor] (size_t const currentFactor)
    {
        factor(value / currentFactor, largestPrimeFactor);
        
        if (currentFactor > largestPrimeFactor && isPrime(currentFactor))
        {
            largestPrimeFactor = currentFactor;
        }
        
        return false;
    };
    
    CallFunctorIfValueHasFactor(value, findLargestPrimeFactor);
}

int main(int argc, const char * argv[])
{
    size_t const numberToBeFactored{600851475143};
    size_t largestFactor{1};
    
    factor(numberToBeFactored, largestFactor);
    
    std::cout << "Largest prime factor of "
    << numberToBeFactored
    << " is "
    << largestFactor
    << std::endl;
    
    return 0;
}
