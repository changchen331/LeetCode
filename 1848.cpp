#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int answer = INT_MAX;
        int size = nums.size();

        if (nums[start] == target)
        {
            return 0;
        }

        for (int i = 0; i < size; i++)
        {
            if (i == start)
            {
                continue;
            }

            int num = nums[i];
            if (num == target)
            {
                answer = min(answer, abs(i - start));
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    int start = 3;

    int answer = solution.getMinDistance(nums, target, start);
    cout << answer << endl;

    return 0;
}
