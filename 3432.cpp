#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        int count = 0;
        for (auto &&num : nums)
            if (num % 2)
                count++;
        if (count % 2)
            return 0;

        int current = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] % 2)
                current++;
            answer += (current % 2) == ((count - current) % 2);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {10, 10, 3, 7, 6};

    int answer = solution.countPartitions(nums);
    cout << answer << endl;

    return 0;
}
