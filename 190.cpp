#include <iostream>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        int answer = 0;
        string temp = "";

        while (n > 0)
        {
            temp.push_back('0' + (n & 1));
            n >>= 1;
        }
        while (temp.length() < 32)
            temp.push_back('0');

        answer = stoi(temp, nullptr, 2);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2147483644;

    int answer = solution.reverseBits(n);
    cout << answer << endl;

    return 0;
}
