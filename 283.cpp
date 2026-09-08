#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int size = nums.size();

        // 方法 1
        // for (int i = 0; i < size; i++)
        // {
        //     int cur = nums[i];
        //     if (cur == 0)
        //     {
        //         nums.erase(nums.begin() + i);
        //         nums.push_back(0);
        //         i--;
        //         size--;
        //     }
        // }

        // 方法 2
        int left = 0;
        int right = 0;
        while (left < size && nums[left] != 0)
        {
            left++;
            right++;
        }

        right++;
        for (; right < size; right++)
        {
            int &cur = nums[right];
            if (cur != 0)
            {
                nums[left] = cur;
                cur = 0;
                left++;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};

    solution.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
