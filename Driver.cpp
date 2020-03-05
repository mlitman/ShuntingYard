#include<iostream>
#include "StringFactory.hpp"
using namespace std;

int main()
{
    string s = "123+42-8*2";
    LinkedList* ll = new LinkedList();
    ll->addEnd("hello");
    ll->addEnd("world");
    ll->addEnd("lol");
    ll->addEnd("woot");
    ll->display();

    StringFactory::split(s,"+-*/");

}
 
