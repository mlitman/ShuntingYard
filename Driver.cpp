#include<iostream>
#include "StringFactory.hpp"

using namespace std;

int main()
{
    string s = "123+42-8*2";
    string ops = "+-*/";
    Queue* inputQ = StringFactory::split(s,ops); 
}
 
