#include <string>

using namespace std;

class ShuntingYard
{
    private:
        string expression;
        string delimiters;
        bool isOperator(string s);
        int getOpPower(string op);
        int stringToInt(string num);
        int indexOf(string s, char c);
        int doMath(char op, int num0, int num1);


    public:
        ShuntingYard(string expression, string delimiters);
};