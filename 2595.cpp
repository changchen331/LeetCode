#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> evenOddBit(int n)
    {
        vector<int> answer{0, 0}; // {偶,奇}

        bool lock = false;
        while (n > 0)
        {
            if (n & 1)
                answer[lock]++;
            lock = !lock;
            n >>= 1;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 50;

    vector<int> answer = solution.evenOddBit(n);
    cout << "[" << answer[0] << "," << answer[1] << "]" << endl;

    return 0;
}
