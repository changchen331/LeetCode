#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int answer = 1, size = nums.size();

        int maximum = 0, count = 0;
        for (auto &&num : nums)
        {
            if (num > maximum)
            {
                answer = count = 1;
                maximum = num;
            }
            else if (num == maximum)
                answer = max(answer, ++count);
            else
                count = 0;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3, 3, 2, 2};

    int answer = solution.longestSubarray(nums);
    cout << answer << endl;

    return 0;
}
