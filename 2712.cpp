#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long minimumCost(string s)
    {
        long long answer = 0;
        int length = s.length();

        // 我的方法（太慢了）
        // vector<long long> left(length);
        // for (int i = 1; i < length; i++)
        //     left[i] = left[i - 1] + (s[i] != s[i - 1] ? i : 0);
        // answer = left[length - 1];
        // long long temp = 0;
        // for (int i = length - 2, count = 1; i >= 0; i--, count++)
        //     answer = min(answer, left[i] + (temp += s[i] != s[i + 1] ? count : 0));

        // 官解
        for (int i = 1; i < length; i++)
            if (s[i] != s[i - 1])
                answer += min(i, length - i);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "010101";

    long long answer = solution.minimumCost(s);
    cout << answer << endl;

    return 0;
}
