#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

const int MAX_N = 30;
vector<long long> ans[10];

// 是否为 k 回文数
bool is_k_palindrome(long long num, int k)
{
    if (num % k == 0)
        return false;

    int rev = 0; // 翻转数
    while (rev < num / k)
    {
        rev = rev * k + num % k;
        num /= k;
    }

    return rev == num || rev == num / k;
}

bool do_palindrome(long long num)
{
    bool done = true;

    for (int k = 2; k < 10; k++)
    {
        if (ans[k].size() < MAX_N && is_k_palindrome(num, k))
            ans[k].push_back(num);
        if (ans[k].size() < MAX_N)
            done = false;
    }
    if (!done)
        return false;

    for (int k = 2; k < 10; k++)
        partial_sum(ans[k].begin(), ans[k].end(), ans[k].begin());

    return true;
}

auto init = []()
{
    for (int base = 1;; base *= 10)
    {
        // 生成奇数长度回文数
        for (int i = base; i < base * 10; i++)
        {
            long long num = i;
            for (int t = i / 10; t > 0; t /= 10)
                num = num * 10 + t % 10;
            if (do_palindrome(num))
                return 0;
        }

        // 生成偶数长度回文数
        for (int i = base; i < base * 10; i++)
        {
            long long num = i;
            for (int t = i; t > 0; t /= 10)
                num = num * 10 + t % 10;
            if (do_palindrome(num))
                return 0;
        }
    }
}();

class Solution
{
public:
    long long kMirror(int k, int n)
    {
        long long answer = 0;

        answer = ans[k][n - 1];

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int k = 2;
    int n = 5;

    long long answer = solution.kMirror(k, n);
    cout << answer << endl;

    return 0;
}
