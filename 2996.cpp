#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int answer = 0;

        int SIZE = 2'000;
        int size = nums.size();

        vector<bool> mem(SIZE, false);
        int head = nums[0];
        mem[head] = true;

        int pre = nums[0];
        bool flag = true;
        for (int i = 1; i < size; i++)
        {
            int cur = nums[i];
            mem[cur] = true;

            if (flag && cur - 1 == nums[i - 1])
            {
                pre += cur;
            }
            else
            {
                flag = false;
            }
        }

        for (int i = pre; i < SIZE; i++)
        {
            if (!mem[i])
            {
                answer = i;
                break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {29, 1, 2, 3, 4, 5};

    int answer = solution.missingInteger(nums);
    cout << answer << endl;

    return 0;
}
