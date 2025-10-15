#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        nums.emplace_back(INT_MIN);
        int answer = 0, size = nums.size();

        int position = 1, last = 0, count = 1;
        for (; position < size; position++)
        {
            if (nums[position - 1] < nums[position])
                count++;
            else
            {
                answer = max(answer, max(count / 2, min(last, count)));
                last = count;
                count = 1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 5};

    int answer = solution.maxIncreasingSubarrays(nums);
    cout << answer << endl;

    return 0;
}
