#include <bit>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumOr(vector<int> &nums, int k)
    {
        long long answer = 0, size = nums.size();

        // 方法一（太慢了）
        // long long memory = 0;
        // sort(nums.begin(), nums.end());
        // // 前缀
        // int length = __bit_width(nums[size - 1]), current = size - 1;
        // for (int i = 0; i < size - 1; i++)
        // {
        //     int num = nums[i];
        //     if (__bit_width(num) == length)
        //     {
        //         current = i;
        //         break;
        //     }
        //     memory |= num;
        // }
        // // 后缀
        // vector<int> memories(size);
        // for (int i = size - 2; i >= current; i--)
        //     memories[i] = memories[i + 1] | nums[i + 1];
        // for (; current < size; current++)
        // {
        //     int num = nums[current];
        //     answer = max(answer, memory | (long long)num << k | memories[current]);
        //     memory |= num;
        // }

        // 方法二
        vector<int> memories(size); // 后缀
        for (int i = size - 2; i >= 0; i--)
            memories[i] = memories[i + 1] | nums[i + 1];
        for (int i = 0, memory = 0; i < size; memory |= nums[i++])
            answer = max(answer, memory | (long long)nums[i] << k | memories[i]);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{12, 9};
    int k = 1;

    long long answer = solution.maximumOr(nums, k);
    cout << answer << endl;

    return 0;
}
