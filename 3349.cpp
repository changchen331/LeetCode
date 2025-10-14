#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        bool answer = false;
        int size = nums.size() - 2 * k;

        for (int i = 0; i <= size; i++)
        {
            // a
            bool flaga = true;
            for (int j = i + 1; j < i + k; j++)
            {
                if (nums[j - 1] >= nums[j])
                {
                    flaga = false;
                    break;
                }
            }
            if (!flaga)
                continue;

            // b
            for (int j = i + k + 1; j < i + 2 * k; j++)
            {
                if (nums[j - 1] >= nums[j])
                {
                    flaga = false;
                    break;
                }
            }
            if (flaga)
            {
                answer = true;
                break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int k = 3;

    bool answer = solution.hasIncreasingSubarrays(nums, k);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
