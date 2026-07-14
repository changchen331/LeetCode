#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;
    int size;
    vector<vector<long long>> memo;

    void dp(vector<int> &nums)
    {
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            auto temp = memo;
            for (int j = 0; j < 201; j++)
            {
                int jj = gcd(j, num);
                for (int k = 0; k < 201; k++)
                {
                    if (memo[j][k] == 0)
                    {
                        continue;
                    }
                    int kk = gcd(k, num);
                    temp[jj][k] = (temp[jj][k] + memo[j][k]) % MOD;
                    temp[j][kk] = (temp[j][kk] + memo[j][k]) % MOD;
                }
            }
            memo = temp;
        }
    }

public:
    int subsequencePairCount(vector<int> &nums)
    {
        int answer = 0;

        size = nums.size();
        memo.resize(201, vector<long long>(201, 0));
        memo[0][0] = 1;

        dp(nums);
        for (int i = 1; i < 201; i++)
        {
            answer = (answer + memo[i][i]) % MOD;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};

    int answer = solution.subsequencePairCount(nums);
    cout << answer << endl;

    return 0;
}
