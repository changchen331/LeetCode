#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        long long answer = 0;

        // 计算阶乘
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++)
            factorial[i] = factorial[i - 1] * i;

        unordered_set<string> memories;
        int base = pow(10, (n - 1) / 2);
        for (int i = base; i < 10 * base; i++)
        {
            string s = to_string(i);
            s += string(s.rbegin() + (n % 2), s.rend());
            if (stoll(s) % k)
                continue;

            sort(s.begin(), s.end());
            if (!memories.insert(s).second)
                continue;

            // 算排列组合
            vector<int> count(10, 0);
            for (auto &&c : s)
                count[c - '0']++;
            int response = (n - count[0]) * factorial[n - 1];
            for (auto &&cou : count)
                response /= factorial[cou];
            answer += response;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    int k = 5;

    long long answer = solution.countGoodIntegers(n, k);
    cout << answer << endl;

    return 0;
}
