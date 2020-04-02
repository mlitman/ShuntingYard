#include<iostream>
#include "StringFactory.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

int main()
{
    string s = "123+42-8*2";
    string ops = "+-*/";
    Queue* inputQ = StringFactory::split(s,ops); 
    inputQ->display();

    Stack* myStack = new Stack();
    for(int i = 0; i < 10; i++)
    {
        myStack->push((string)"" + to_string(i));
    }

    myStack->display();
}

 
