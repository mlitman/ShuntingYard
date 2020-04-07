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
    
    //do the math
    Stack* mathStack = new Stack();
    while(!outputQ->isEmpty())
    {
        temp = outputQ->dequeue();
        if(this->isOperator(temp))
        {
            int num1 = this->stringToInt(mathStack->pop());
            int num0 = this->stringToInt(mathStack->pop());
            int answer = this->doMath(temp[0], num0, num1);
            mathStack->push((to_string(answer)));
        }
        else
        {
            mathStack->push(temp);
        }
    }
    cout << mathStack->peek() << "\n";
}

int ShuntingYard::doMath(char op, int num0, int num1)
{
    if(op == '+')
    {
        return num0 + num1;
    }
    else if(op == '-')
    {
        return num0 - num1;
    }
    else if(op == '*')
    {
        return num0 * num1;
    }
    else if(op == '/')
    {
        return num0 / num1;
    }
}

int ShuntingYard::indexOf(string s, char c)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int ShuntingYard::stringToInt(string num)
{
    int sum = 0;
    string theNumbers = "0123456789";
    int place = 1;
    for(int i = num.length()-1; i >= 0; i--)
    {
        sum += (place * this->indexOf(theNumbers, num[i]));
        place *= 10;
    }
    return sum;
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