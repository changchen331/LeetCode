#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int size = nums.size();
        vector<bool> numbers(101, false);

        for (int i = size - 1; i >= 0; i--)
        {
            if (numbers[nums[i]])
                return i / 3 + 1;

            numbers[nums[i]] = true;
        }

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 2, 3, 3, 5, 7};

    int answer = solution.minimumOperations(nums);
    cout << answer << endl;

    return 0;
}
