#ifndef StringFactory_hpp
#define StringFactor_hpp
#include "Queue.hpp"
#include <iostream>

using namespace std;

class StringFactory
{
    public:
        static Queue* split(string s, string delims);
    
    private:
        static bool isInString(string searchString, char charToFind);
};
#endif