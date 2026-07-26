#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int answer = INT_MIN;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        // 方法一
        // int p0 = 1, p1 = 1, p2 = 1, p3 = 1;
        // auto p = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        // int pos = (p < size) && (nums[p] == 0) && (size - p > 3) ? p + 1 : p;
        // int neg = p - 1;
        // // p0
        // if (neg > 1)
        // {
        //     for (int i = 0; i <= 2; i++)
        //     {
        //         p0 *= nums[neg - i];
        //     }
        //     answer = max(answer, p0);
        // }
        // // p1
        // if (pos < size && neg > 0)
        // {
        //     p1 *= nums.back();
        //     for (int i = 0; i <= 1; i++)
        //     {
        //         p1 *= nums[i];
        //     }
        //     answer = max(answer, p1);
        // }
        // // p2
        // if (pos < size - 1 && neg >= 0)
        // {
        //     for (int i = 0; i <= 1; i++)
        //     {
        //         p2 *= nums[pos + i];
        //     }
        //     p2 *= nums[neg];
        //     answer = max(answer, p2);
        // }
        // // p3
        // if (pos < size - 2)
        // {
        //     for (int i = 1; i <= 3; i++)
        //     {
        //         p3 *= nums[size - i];
        //     }
        //     answer = max(answer, p3);
        // }

        // 方法二
        int max1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int max2 = nums[0] * nums[1] * nums[size - 1];
        answer = max(max1, max2);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 0, 100};

    int answer = solution.maximumProduct(nums);
    cout << answer << endl;

    return 0;
}
