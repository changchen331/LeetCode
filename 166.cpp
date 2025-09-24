#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string answer = "";

        string minus, integer, decimal;

        // 负号
        minus = (numerator < 0) ^ (denominator < 0) ? "-" : "";

        // 整数
        long long nume = (numerator < 0 ? -1 : 1) * (long long)numerator;
        long long deno = (denominator < 0 ? -1 : 1) * (long long)denominator;
        integer = to_string(nume / deno);

        // 小数
        unordered_map<int, int> remainders; // <余数,index>
        int index = 0;
        nume %= deno;
        remainders[nume] = index++;
        while (nume != 0)
        {
            nume *= 10;
            decimal += to_string(nume / deno);
            nume %= deno;
            if (remainders.find(nume) != remainders.end())
            {
                decimal.insert(remainders[nume], 1, '(');
                decimal = decimal + ")";
                break;
            }
            remainders[nume] = index++;
        }

        answer = minus + integer + (decimal.length() > 0 ? ('.' + decimal) : "");
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int numerator = -1;
    int denominator = -2147483648;

    string answer = solution.fractionToDecimal(numerator, denominator);
    cout << answer << endl;

    return 0;
}
