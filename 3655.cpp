#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;

    long long pow(long long num, int n)
    {
        long long response = 1;

        for (; n; n /= 2)
        {
            if (n % 2)
            {
                response = response * num % MOD;
            }
            num = num * num % MOD;
        }

        return response;
    }

public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int answer = 0;
        int sizen = nums.size(), sizeq = queries.size();

        int B = sqrt(sizeq);
        vector<vector<int>> diff(B);

        for (auto &&query : queries)
        {
            int l = query[0], r = query[1], k = query[2];
            long long v = query[3];

            if (k < B)
            {
                // 商分数组
                auto &dk = diff[k];
                if (dk.empty())
                {
                    dk.resize(sizen + k, 1);
                }

                dk[l] = dk[l] * v % MOD;
                r = r - (r - l) % k + k;
                dk[r] = dk[r] * pow(v, MOD - 2) % MOD;
            }
            else
            {
                // 模拟
                for (int i = l; i <= r; i += k)
                {
                    nums[i] = nums[i] * v % MOD;
                }
            }
        }

        for (int k = 1; k < B; k++)
        {
            auto &dk = diff[k];
            if (dk.empty())
            {
                continue;
            }

            for (int start = 0; start < k; start++)
            {
                long long mul_d = 1;
                for (int i = start; i < sizen; i += k)
                {
                    mul_d = mul_d * dk[i] % MOD;
                    nums[i] = nums[i] * mul_d % MOD;
                }
            }
        }

        for (auto &&num : nums)
        {
            answer ^= num;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};

    int answer = solution.xorAfterQueries(nums, queries);
    cout << answer << endl;

    return 0;
}
