#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> answer(k, 0);
        int size = nums.size();

        vector<pair<int, int>> values;
        for (int i = 0; i < size; i++)
            values.push_back({i, nums[i]});

        // 按照数值排序（从大到小）
        sort(values.begin(), values.end(), [&](auto x1, auto x2)
             { return x1.second > x2.second; });
        // 按照下标升序排序（前 k 个）
        sort(values.begin(), values.begin() + k);

        for (int i = 0; i < k; i++)
            answer[i] = values[i].second;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{2, 1, 3, 3};
    int k = 2;

    vector<int> answer = solution.maxSubsequence(nums, k);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
