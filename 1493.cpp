#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        bool not_delete = true;
        for (int front = 0, back = 0, count = 0; front < size; front++)
        {
            if (nums[front] == 0)
            {
                if (not_delete)
                    not_delete = false;
                else
                {
                    while (back < front)
                    {
                        if (nums[back++] == 0)
                            break;
                        count--;
                    }
                }
            }
            else
                answer = max(answer, ++count);
        }

        return answer - not_delete;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};

    int answer = solution.longestSubarray(nums);
    cout << answer << endl;

    return 0;
}
