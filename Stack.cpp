#include "Stack.hpp"

Stack::Stack()
{
    this->top = 0;
    this->count = 0;
}

void Stack::display()
{
    Node* currNode = this->top;
    while(currNode)
    {
        cout << currNode->getPayload();
        currNode = currNode->getNextNode();
    }
    cout << "\n";
}

void Stack::push(string s)
{
    Node* n = new Node(s);
    if(this->top)
    {
        n->setNextNode(this->top);
    }
    this->top = n;
    this->count++;
}

string Stack::pop()
{
    if(this->top)
    {
        Node* temp = this->top;
        this->top = this->top->getNextNode();
        string payload2Return = temp->getPayload();
        delete temp;
        return payload2Return;
    }
    return 0;
}

string Stack::peek()
{
    if(this->top)
    {
        return this->top->getPayload();
    }
    return 0;
}

int Stack::getCount()
{
    return this->count;
}