#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> record;
        for (auto &&num : nums)
            if (!record.insert(num).second)
                return num;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};

    int answer = solution.repeatedNTimes(nums);
    cout << answer << endl;

    return 0;
}
