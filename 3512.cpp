#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int answer = 0, size = nums.size();

        int total = 0;
        for (auto &&num : nums)
            total += num;
        if (total < k)
            return total;

        answer = total % k;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 9, 7};
    int k = 5;

    int answer = solution.minOperations(nums, k);
    cout << answer << endl;

    return 0;
}
