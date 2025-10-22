#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        unordered_map<int, int> cnt;
        map<int, int> diff;
        for (int x : nums)
        {
            cnt[x]++;
            diff[x];       // 把 x 插入 diff，以保证下面能遍历到 x
            diff[x - k]++; // 把 [x-k, x+k] 中的每个整数的出现次数都加一
            diff[x + k + 1]--;
        }

        int ans = 0, sum_d = 0;
        for (auto &[x, d] : diff)
        {
            sum_d += d;
            ans = max(ans, min(sum_d, cnt[x] + numOperations));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 4, 5};
    int k = 1;
    int numOperations = 2;

    int answer = solution.maxFrequency(nums, k, numOperations);
    cout << answer << endl;

    return 0;
}
