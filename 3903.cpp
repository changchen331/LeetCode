#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int answer = -1;

        int size = nums.size();
        vector<int> pre_max(size, nums[0]);
        vector<int> suf_min(size, nums.back());

        for (int l = 1, r = size - 2; l < size; l++, r--)
        {
            int left = nums[l];
            pre_max[l] = max(pre_max[l - 1], left);

            int right = nums[r];
            suf_min[r] = min(suf_min[r + 1], right);
        }

        for (int i = 0; i < size; i++)
        {
            int temp = pre_max[i] - suf_min[i];
            if (temp <= k)
            {
                answer = i;
                break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 1};
    int k = 1;

    int answer = solution.firstStableIndex(nums, k);
    cout << answer << endl;

    return 0;
}
