#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int answer = 0;

        int size = nums.size();
        int pos = 0;
        while (pos < size - 1)
        {
            if (pos + nums[pos] >= size - 1)
            {
                answer++;
                break;
            }

            int maxi = pos;
            for (int i = 1; i <= nums[pos]; i++)
            {
                int cur = nums[pos + i];
                if (pos + i + cur >= maxi + nums[maxi])
                {
                    maxi = pos + i;
                }
            }
            pos = maxi;
            answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 0, 1, 4};

    int answer = solution.jump(nums);
    cout << answer << endl;

    return 0;
}
