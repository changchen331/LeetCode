#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int answer = INT_MAX;

        for (auto &&num : nums)
        {
            string s = to_string(num);
            int count = 0;
            for (auto &&c : s)
            {
                count += c - '0';
                if (count >= answer)
                {
                    break;
                }
            }
            if (count < answer)
            {
                answer = count;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {10, 12, 13, 14};

    int answer = solution.minElement(nums);
    cout << answer << endl;

    return 0;
}
