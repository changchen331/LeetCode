#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        // 我的方法
        // int count = 1, position = 1;
        // for (int i = 1; i < size; i++)
        // {
        //     if (nums[i - 1] == nums[i] && ++count > 2)
        //         continue;
        //     else if (nums[i - 1] != nums[i])
        //         count = 1;
        //     nums[position++] = nums[i];
        // }
        // return position;

        // 官解
        int stack_size = 2;
        for (int i = 2; i < size; i++)
            if (nums[i] != nums[stack_size - 2])
                nums[stack_size++] = nums[i];
        return min(stack_size, size);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 1, 1, 2, 2, 3};

    int answer = solution.removeDuplicates(nums);
    cout << answer << endl;
    for (auto &&num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
