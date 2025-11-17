#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int size = nums.size();

        int record = -1;
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            if (num == 1)
            {
                if (record != -1 && i - record <= k)
                    return false;
                record = i;
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 0, 0, 1, 0, 1};
    int k = 2;

    bool answer = solution.kLengthApart(nums, k);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
