//
//  ProjEulerHelpers.h
//  Project Euler CPP
//
//  Copyright © 2017 castellanese. All rights reserved.
//

#ifndef PROBLEM_UTILITIES_H
#define PROBLEM_UTILITIES_H

namespace num
{
    template<typename Numeric>
    inline bool isEven(Numeric const value)
    {
        return value % 2 == 0;
    }
    
    template<typename Numeric>
    inline bool isPrime(Numeric const value)
    {
        for (auto i=2; i < value; ++i)
        {
            if (value % i == 0)
            {
                return false;
            }
        }
        
        return true;
    }
}

#endif /* PROBLEM_UTILITIES_H */
