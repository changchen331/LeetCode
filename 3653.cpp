#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;

public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int answer = 0;

        for (auto &&query : queries)
        {
            for (int i = query[0]; i <= query[1]; i += query[2])
            {
                long long temp = nums[i];
                nums[i] = (temp * query[3]) % MOD;
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
    vector<int> nums = {1, 1, 1};
    vector<vector<int>> queries = {{0, 2, 1, 4}};

    int answer = solution.xorAfterQueries(nums, queries);
    cout << answer << endl;

    return 0;
}
