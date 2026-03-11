#include <iostream>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int answer = 0;
        if (n == 0)
            return 1;

        string s = "";
        int temp = n;
        while (temp > 0)
        {
            s.push_back('1');
            temp >>= 1;
        }
        answer = stoi(s, nullptr, 2) - n;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    int answer = solution.bitwiseComplement(n);
    cout << answer << endl;

    return 0;
}
