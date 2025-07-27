#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (int i = 1; i < size - 1; i++)
        {
            int current = nums[i];

            // 前
            int front = i - 1;
            for (; front > 0; front--)
                if (nums[front] != current)
                    break;
            front = nums[front];

            // 后
            int behind = i + 1;
            for (; behind < size - 1; behind++, i++)
                if (nums[behind] != current)
                    break;
            behind = nums[behind];

            // 判断
            answer += (front < current && current > behind) ||
                      (front > current && current < behind);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{6, 6, 5, 5, 4, 1};

    int answer = solution.countHillValley(nums);
    cout << answer << endl;

    return 0;
}
