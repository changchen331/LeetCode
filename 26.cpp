#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        int position = 1;
        for (int i = 1; i < size; i++)
        {
            if (nums[i - 1] == nums[i])
                continue;
            else
                nums[position++] = nums[i];
        }
        return position;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int answer = solution.removeDuplicates(nums);
    cout << answer << endl;
    for (auto &&num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
