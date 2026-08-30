#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int answer = 0;
        int size = nums.size();

        int minp = 0, maxp = 0;
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            if (num < nums[minp])
            {
                minp = i;
            }
            else if (num > nums[maxp])
            {
                maxp = i;
            }
        }

        int maxi = max(minp, maxp);
        int mini = min(minp, maxp);
        int a = maxi + 1;
        int b = size - mini;
        int c = mini + 1 + size - maxi;

        answer = min(c, min(a, b));
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, -4, 19, 1, 8, -2, -3, 5};

    int answer = solution.minimumDeletions(nums);
    cout << answer << endl;

    return 0;
}
