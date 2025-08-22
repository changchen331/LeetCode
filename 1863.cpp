#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        int top = 1 << size;
        for (int i = 1; i < top; i++)
        {
            int temp = i, current = 0;
            for (int j = 0; temp > 0; j++)
            {
                if (temp & 1)
                {
                    if (current == 0)
                        current = nums[j];
                    else
                        current ^= nums[j];
                }
                temp >>= 1;
            }
            answer += current;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 4, 5, 6, 7, 8};

    int answer = solution.subsetXORSum(nums);
    cout << answer << endl;

    return 0;
}
