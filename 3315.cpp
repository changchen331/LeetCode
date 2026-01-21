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
            if (num == 2)
                continue;

            int position = 1;
            for (int current = 2;; current <<= 1, position++)
                if (!(num & current))
                    break;

            answer[i] = num - (1 << (position - 1));
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
