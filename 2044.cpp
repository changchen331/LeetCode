#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int answer = 0, maximum = 0, size = (2 << (nums.size() - 1));

        for (int i = 1; i < size; i++)
        {
            int count = 0;

            for (int position = 0; (1 << position) <= i; position++)
                if (i & (1 << position))
                    count |= nums[position];

            if (count > maximum)
            {
                maximum = count;
                answer = 0;
            }
            answer += (count == maximum);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 2, 1, 5};

    int answer = solution.countMaxOrSubsets(nums);
    cout << answer << endl;

    return 0;
}
