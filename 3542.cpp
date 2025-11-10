#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        if (size == 1)
            return nums[0] != 0;

        // 模拟（超时）
        // int start = 0, end = size - 1;
        // while (start < size && nums[start] == 0)
        //     start++;
        // while (end > -1 && nums[end] == 0)
        //     end--;

        // while (start <= end)
        // {
        //     int min_position = start;
        //     for (int i = start; i <= end; i++)
        //     {
        //         if (nums[i] == 0 || i == end)
        //         {
        //             int minimum = nums[min_position];
        //             for (int j = min_position; j <= i; j++)
        //                 if (nums[j] > 0 && nums[j] == minimum)
        //                     nums[j] = 0;
        //             answer++;

        //             while (i < end && nums[i] == 0)
        //                 i++;
        //             min_position = i;
        //         }
        //         min_position = (nums[min_position] > nums[i]) ? i : min_position;

        //         while (start < size && nums[start] == 0)
        //             start++;
        //         while (end > -1 && nums[end] == 0)
        //             end--;
        //     }
        // }
        // return answer;

        // 单调栈
        vector<int> stack = {0};
        for (auto &&num : nums)
        {
            if (num > stack.back())
                stack.emplace_back(num);
            else if (num < stack.back())
            {
                while (num < stack.back())
                {
                    stack.pop_back();
                    answer++;
                }
                if (num > stack.back())
                    stack.emplace_back(num);
            }
        }

        return answer + stack.size() - 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 1, 2, 1};

    int answer = solution.minOperations(nums);
    cout << answer << endl;

    return 0;
}
