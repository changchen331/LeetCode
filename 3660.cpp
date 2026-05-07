#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size);

        vector<int> pre_max(size);
        pre_max[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            pre_max[i] = max(nums[i], pre_max[i - 1]);
        }

        int suf_min = INT_MAX;
        for (int i = size - 1; i > -1; i--)
        {
            answer[i] = (pre_max[i] <= suf_min) ? pre_max[i] : answer[i + 1];
            suf_min = min(suf_min, nums[i]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 1};

    vector<int> answer = solution.maxValue(nums);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
