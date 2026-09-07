#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int answer = 0;
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }

        // 超时
        // unordered_set<int> mem;
        // for (int i = 0; i < size; i++)
        // {
        //     mem.insert(nums[i]);
        // }

        // for (int i = 0; i < size; i++)
        // {
        //     int cur = nums[i];
        //     if (mem.find(cur - 1) != mem.end())
        //     {
        //         continue;
        //     }

        //     int count = 1;
        //     for (int i = 1;; i++)
        //     {
        //         if (mem.find(cur + i) != mem.end())
        //         {
        //             count++;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     answer = max(answer, count);
        // }

        // 方法 2
        sort(nums.begin(), nums.end());
        int count = 1;
        for (int i = 1; i < size; i++)
        {
            int cur = nums[i];
            if (cur - 1 == nums[i - 1])
            {
                count++;
            }
            else if (cur == nums[i - 1])
            {
                continue;
            }
            else
            {
                answer = max(answer, count);
                count = 1;
            }
        }
        answer = max(answer, count);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2, 2};

    int answer = solution.longestConsecutive(nums);
    cout << answer << endl;

    return 0;
}
