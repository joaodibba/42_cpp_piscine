#include "whatever.hpp"
#include <iostream>
#include <string>
#include <float.h>
#include <limits.h>

int main()
{
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    {
        std::string s1 = "string1";
        std::string s2 = "string2";
    
        std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    
        swap(s1, s2);
    
        std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;

    }
    {
        int first = INT_MAX;
        int second = 32;

        std::cout << "Before swap: first = " << first << ", second = " << second << std::endl;
        
        swap(first, second);

        std::cout << "After swap: first = " << first << ", second = " << second << std::endl;

        std::cout << "min(first, second) = " << min(first, second) << std::endl;
        std::cout << "max(first, second) = " << max(first, second) << std::endl;
    }
    {
        float first = FLT_MAX;
        float second = 32.0f;

        std::cout << "Before swap: first = " << first << ", second = " << second << std::endl;
        
        swap(first, second);

        std::cout << "After swap: first = " << first << ", second = " << second << std::endl;

        std::cout << "min(first, second) = " << min(first, second) << std::endl;
        std::cout << "max(first, second) = " << max(first, second) << std::endl;
    }
    {
        double first = DBL_MAX;
        double second = 64;

        std::cout << "Before swap: first = " << first << ", second = " << second << std::endl;
        
        swap(first, second);

        std::cout << "After swap: first = " << first << ", second = " << second << std::endl;

        std::cout << "min(first, second) = " << min(first, second) << std::endl;
        std::cout << "max(first, second) = " << max(first, second) << std::endl;
    }
    {
        long double first = LDBL_MAX;
        long double second = 80;

        std::cout << "Before swap: first = " << first << ", second = " << second << std::endl;
        
        swap(first, second);

        std::cout << "After swap: first = " << first << ", second = " << second << std::endl;

        std::cout << "min(first, second) = " << min(first, second) << std::endl;
        std::cout << "max(first, second) = " << max(first, second) << std::endl;
    }
    return 0;
}