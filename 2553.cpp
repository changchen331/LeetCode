#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer;

        for (int i = 0; i < size; i++)
        {
            int current = nums[i];
            string s = to_string(current);
            for (auto &&c : s)
            {
                answer.push_back(c - '0');
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {13, 25, 83, 77};

    vector<int> answer = solution.separateDigits(nums);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
