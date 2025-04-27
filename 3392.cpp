#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (int i = 0; i < size - 2; i++)
            answer += (nums[i] + nums[i + 2]) == ((float)nums[i + 1] / 2);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{-1, -4, -1, 4};

    int answer = solution.countSubarrays(nums);
    cout << answer << endl;

    return 0;
}
