#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool go(vector<int> nums, int current, int step)
    {
        current += step;
        while (-1 < current && current < nums.size())
        {
            if (nums[current] > 0)
            {
                nums[current]--;
                step *= -1;
            }
            current += step;
        }

        for (auto &&num : nums)
            if (num)
                return false;
        return true;
    }

public:
    int countValidSelections(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (int i = 0; i < size; i++)
            if (nums[i] == 0)
                answer += go(nums, i, -1) + go(nums, i, 1);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 0, 2, 0, 3};

    int answer = solution.countValidSelections(nums);
    cout << answer << endl;

    return 0;
}
