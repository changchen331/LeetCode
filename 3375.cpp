#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int answer = 0;

        vector<bool> count(100, false);
        for (auto &&num : nums)
        {
            if (num < k)
                return -1;
            if (num == k)
                continue;

            if (!count[num])
                answer += count[num] = true;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{5, 2, 5, 4, 5};
    int k = 2;

    int answer = solution.minOperations(nums, k);
    cout << answer << endl;

    return 0;
}
