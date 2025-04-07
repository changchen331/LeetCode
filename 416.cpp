#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool dfs(vector<int> &nums, vector<vector<int>> &memories, int current, int need)
    {
        if (current < 0)
            return need == 0;
        int &memory = memories[current][need];
        if (memory >= 0)
            return memory;

        int num = nums[current];
        return memory = (need >= num &&
                         dfs(nums, memories, current - 1, need - num)) ||
                        dfs(nums, memories, current - 1, need);
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2)
            return false;

        int size = nums.size();
        vector<vector<int>> memories(size, vector<int>(total / 2 + 1, -1));
        return dfs(nums, memories, size - 1, total / 2);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 5, 11, 5};

    bool answer = solution.canPartition(nums);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
