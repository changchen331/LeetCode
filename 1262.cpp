#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (auto &&num : nums)
            answer += num;
        if (answer % 3 == 0)
            return answer;

        int one1 = 10'000, one2 = 10'000;
        int two1 = 10'000, two2 = 10'000;
        for (auto &&num : nums)
        {
            if (num % 3 == 1)
            {
                if (num < one1)
                {
                    one2 = one1;
                    one1 = num;
                }
                else if (num < one2)
                    one2 = num;
            }
            else if (num % 3 == 2)
            {
                if (num < two1)
                {
                    two2 = two1;
                    two1 = num;
                }
                else if (num < two2)
                    two2 = num;
            }
        }

        int loss1 = min(one1, two1 + two2), loss2 = min(one1 + one2, two1);
        if (answer % 3 == 1)
            answer -= loss1;
        else if (answer % 3 == 2)
            answer -= loss2;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 6, 5, 1, 8};

    int answer = solution.maxSumDivThree(nums);
    cout << answer << endl;

    return 0;
}
