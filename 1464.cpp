#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int answer = 0;
        int size = nums.size();

        int a = INT_MIN, b = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            int n = nums[i];
            if (n > a)
            {
                b = a;
                a = n;
            }
            else if (n > b)
            {
                b = n;
            }
        }
        answer = (a - 1) * (b - 1);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 4, 5, 2};

    int answer = solution.maxProduct(nums);
    cout << answer << endl;

    return 0;
}
