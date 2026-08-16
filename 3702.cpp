#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int answer = 0;
        int size = nums.size();

        int mem = 0;
        bool bigthan0 = false;
        for (int i = 0; i < size; i++)
        {
            int cur = nums[i];
            if (!bigthan0 && cur != 0)
            {
                bigthan0 = true;
            }
            mem ^= nums[i];
        }

        if (mem == 0)
        {
            if (bigthan0)
            {

                answer = size - 1;
            }
        }
        else
        {
            answer = size;
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0};

    int answer = solution.longestSubsequence(nums);
    cout << answer << endl;

    return 0;
}
