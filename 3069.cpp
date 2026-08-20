#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> answer;
        int size = nums.size();

        answer.push_back(nums[0]);
        answer.push_back(nums[1]);
        int l = 0;
        for (int i = 2; i < size; i++)
        {
            int cur = nums[i];
            if (answer[l] > answer.back())
            {
                answer.insert(answer.begin() + l + 1, cur);
                l++;
            }
            else
            {
                answer.push_back(cur);
            }
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 4, 3, 8};

    vector<int> answer = solution.resultArray(nums);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i < answer.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
