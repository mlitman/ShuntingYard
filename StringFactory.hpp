#include "Queue.hpp"
#include <iostream>

using namespace std;

class StringFactory
{
    public:
        static Queue* split(string s, string delims);
};