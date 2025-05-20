#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int size = nums.size();

        vector<int> diff(size + 1, 0);
        for (auto &&query : queries)
        {
            diff[query[0]]--;
            diff[query[1] + 1]++;
        }

        for (int i = 0, count = 0; i < size; i++)
        {
            count += diff[i];
            if (nums[i] + count > 0)
                return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 0, 1};
    vector<vector<int>> queries{{0, 2}};

    bool answer = solution.isZeroArray(nums, queries);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
