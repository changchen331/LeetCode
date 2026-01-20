#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, -1);

        for (int i = 0; i < size; i++)
        {
            int &num = nums[i];
            for (int j = 1; j < num; j++)
            {
                if ((j | (j + 1)) == num)
                {
                    answer[i] = j;
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 5, 7};

    vector<int> answer = solution.minBitwiseArray(nums);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
