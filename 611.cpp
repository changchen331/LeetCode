#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        sort(nums.begin(), nums.end());

        // 方法一(时间复杂度太高)
        // for (int left = 0, right; left < size - 2; left++)
        // {
        //     int &l = nums[left];
        //     for (int right = left + 1; right < size - 1; right++)
        //     {
        //         int &r = nums[right];
        //         for (int i = size - 1; i > right; i--)
        //         {
        //             int &temp = nums[i];
        //             if (l + r > temp)
        //             {
        //                 answer += i - right;
        //                 break;
        //             }
        //         }
        //     }
        // }

        // 方法二
        for (int k = 2; k < size; k++)
        {
            int &current = nums[k];

            int left = 0;
            int right = k - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > current)
                    answer += right-- - left;
                else
                    left++;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 2, 3, 4};

    int answer = solution.triangleNumber(nums);
    cout << answer << endl;

    return 0;
}
