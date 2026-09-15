#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answer;
        int size = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int diff = -nums[i];

            int l = i + 1;
            int r = size - 1;
            for (; l < r;)
            {
                int sum = nums[l] + nums[r];
                if (sum < diff)
                {
                    l++;
                }
                else if (sum > diff)
                {
                    r--;
                }
                else
                {
                    answer.push_back({-diff, nums[l++], nums[r]});
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 0, 0, 0};

    vector<vector<int>> answer = solution.threeSum(nums);
    for (int i = 0; i < answer.size(); i++)
    {
        vector<int> &ans = answer[i];
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    return 0;
}
