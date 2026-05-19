#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int size = nums.size();

        unordered_map<int, int> counts;
        for (auto &&num : nums)
        {
            int count = ++counts[num];
            if (num < size - 1 && count > 1)
            {
                return false;
            }
            else if (num >= size || count > 2)
            {
                return false;
            }
        }

        return counts.size() == size - 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 7, 3, 1, 5, 2, 6, 4};

    bool answer = solution.isGood(nums);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
