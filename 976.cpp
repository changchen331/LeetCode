#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = size - 2; i > 0; i--)
        {
            int &a = nums[i - 1], &b = nums[i], &c = nums[i + 1];
            if (a + b > c)
            {
                answer = a + b + c;
                break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 1, 2};

    int answer = solution.largestPerimeter(nums);
    cout << answer << endl;

    return 0;
}
