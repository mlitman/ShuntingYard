#include <string>

using namespace std;

class ShuntingYard
{
    private:
        string expression;
        string delimiters;
        bool isOperator(string s);
        int getOpPower(string op);


    public:
        ShuntingYard(string expression, string delimiters);
};