#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        else if (size == 2)
        {
            return min(nums[0], nums[1]);
        }

        int answer = nums[0];

        int left = 0, right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid != 0 && nums[mid - 1] > nums[mid])
            {
                return nums[mid];
            }

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid - 1;
            }
            else
            {
                break;
            }
        }

        answer = nums[left];
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {11, 13, 15, 17};

    int answer = solution.findMin(nums);
    cout << answer << endl;

    return 0;
}
