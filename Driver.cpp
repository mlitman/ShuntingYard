#include<iostream>
#include "ShuntingYard.hpp"

using namespace std;

int main()
{
    string s = "123+42-8*2";
    string ops = "+-*/";
    
    ShuntingYard* sy = new ShuntingYard(s, ops);
}

 
