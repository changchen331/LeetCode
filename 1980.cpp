#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string answer = "";
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            if (nums[i][i] == '0')
            {
                answer.push_back('1');
            }
            else
            {
                answer.push_back('0');
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> nums = {"111", "011", "001"};

    string answer = solution.findDifferentBinaryString(nums);
    cout << answer << endl;

    return 0;
}
