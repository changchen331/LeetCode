#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> answer;
        int size = nums.size();

        int num = 0;
        for (int i = 0; i < size; i++, num <<= 1)
        {
            num = (num + nums[i]) % 5;
            answer.push_back(num % 5 == 0);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1};

    vector<bool> answer = solution.prefixesDivBy5(nums);
    for (auto &&ans : answer)
        cout << (ans ? "true" : "false") << " ";
    cout << endl;

    return 0;
}
