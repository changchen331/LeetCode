#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        int record = nums[0];

        // 判断最大公因数是否为 1
        int count = nums[0] == 1;
        for (int i = 1; i < size; i++)
        {
            record = gcd(record, nums[i]);
            count += nums[i] == 1;
        }
        if (record != 1)
            return -1;

        // 如果存在 1
        if (count > 0)
            return size - count;

        // 暴力
        int minimum = INT_MAX;
        for (int i = 0; i < size - 1; i++)
        {
            record = nums[i];
            for (int j = i + 1; j < size; j++)
            {
                record = gcd(record, nums[j]);
                if (record == 1)
                {
                    minimum = min(minimum, j - i);
                    break;
                }
            }
            if (minimum == 1)
                break;
        }

        answer = minimum + size - 1;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 1};

    int answer = solution.minOperations(nums);
    cout << answer << endl;

    return 0;
}
