#include "ShuntingYard.hpp"
#include "StringFactory.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

ShuntingYard::ShuntingYard(string expression, string delimiters)
{
    this->expression = expression;
    this->delimiters = delimiters;
    Queue* inputQ = StringFactory::split(this->expression,this->delimiters); 
    Stack* opStack = new Stack();
    Queue* outputQ = new Queue();

    //perform the shunting yard logic
    string temp;
    while(!inputQ->isEmpty())
    {
        temp = inputQ->dequeue();
        if(this->isOperator(temp))
        {
            //do the op stuff
            char op = temp[0];
            if(op == '(')
            {
                opStack->push(temp);
            }
            else if(op == ')')
            {
                //clear the op stack of everything that belongs to the )
                string tempOp = opStack->pop();
                while(tempOp[0] != '(')
                {
                    outputQ->enqueue(tempOp);
                    tempOp = opStack->pop();
                }
            }
            else
            {
                //have an operator and need to TRY to push onto the stack
                while(!opStack->isEmpty() && 
                    this->getOpPower(opStack->peek()) >= this->getOpPower(temp))
                    {
                        outputQ->enqueue(opStack->pop());
                    }
                opStack->push(temp);
            } 
        }
        else
        {
            outputQ->enqueue(temp);
        } 
    }

    //done processing inputQ, now clear the stack
    while(!opStack->isEmpty())
    {
        outputQ->enqueue(opStack->pop());
    }
    outputQ->display();
}

int ShuntingYard::getOpPower(string op)
{
    if(op[0] == '*' || op[0] == '/')
    {
        return 3;
    }
    else
    {
        return 2;
    } 
}

bool ShuntingYard::isOperator(string s)
{
    char c = s[0];
    for(int i = 0; i < this->delimiters.length(); i++)
    {
        if(c == this->delimiters[i])
        {
            return true;
        }
    }
    return false;
}