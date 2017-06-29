//
//  main.cpp
//  Problem4
//
//      A palindromic number reads the same both ways. The largest palindrome
//      made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
//      Find the largest palindrome made from the product of two 3-digit
//      numbers.
//
//  Copyright © 2017 castellanese. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

std::vector<size_t> SplitNumberIntoDigits(size_t number)
{
    std::vector<size_t> digitsOfNumber;
    
    size_t digitAtOnesPlace{0};
    
    while (number > 0)
    {
        digitAtOnesPlace = number % 10;
        digitsOfNumber.push_back(digitAtOnesPlace);
        number = number / 10;
    }
    
    return digitsOfNumber;
}

inline bool isEven(size_t const number)
{
    return number % 2 == 0;
}

bool isPalindrome(size_t product)
{
    std::vector<size_t> digitsOfProduct = SplitNumberIntoDigits(product);
    
    if (!isEven(digitsOfProduct.size()))
    {
        return false;
    }
    
    auto forwardPointer = digitsOfProduct.cbegin();
    auto backwardPointer = digitsOfProduct.cend() - 1;
    
    while (*forwardPointer == *backwardPointer)
    {
        ++forwardPointer;
        --backwardPointer;
    }
    
    return forwardPointer > backwardPointer;
}

int main()
{
    size_t const firstThreeDigitNumber{100};
    size_t const firstFourDigitNumber{1000};
    
    size_t currentProduct{0};
    size_t maxPalindromeProduct{0};
    
    for (auto i=firstThreeDigitNumber; i < firstFourDigitNumber; ++i)
    {
        for (auto j=i+1; j < firstFourDigitNumber; ++j)
        {
            currentProduct = i * j;
            
            if (currentProduct > maxPalindromeProduct
                && isPalindrome(currentProduct))
            {
                maxPalindromeProduct = currentProduct;
            }
        }
    }
    
    std::cout << "The largest palindrome product of two three digit numbers is "
    << maxPalindromeProduct
    << std::endl;
    
    return 0;
}
