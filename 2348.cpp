#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long answer = 0;
        int size = nums.size();

        int start = -1;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] != 0)
            {
                if (start + 1 < i)
                    answer += 1LL * (i - start - 1) * (i - start) / 2;
                start = i;
            }
        }

        if (start + 1 < size)
            answer += 1LL * (size - start - 1) * (size - start) / 2;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 0, 0, 2, 0, 0};

    long long answer = solution.zeroFilledSubarray(nums);
    cout << answer << endl;

    return 0;
}
