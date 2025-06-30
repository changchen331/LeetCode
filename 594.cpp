#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        sort(nums.begin(), nums.end());

        int head = 0, tail = 0;
        while (head < size)
        {
            if (size - head <= answer)
                break;

            int diff = nums[tail] - nums[head];
            if (diff < 1)
            {
                if (tail < size - 1)
                    tail++;
                else
                    head++;
            }
            else if (diff > 1)
                head++;
            else
            {
                answer = max(answer, tail - head + 1);
                if (tail < size - 1)
                    tail++;
                else
                    head++;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};

    int answer = solution.findLHS(nums);
    cout << answer << endl;

    return 0;
}
