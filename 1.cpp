#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> answer(2, -1);
        int size = nums.size();

        unordered_map<int, vector<int>> mem;
        for (int i = 0; i < size; i++)
        {
            int cur = nums[i];
            mem[cur].push_back(i);
        }

        for (int i = 0; i < size; i++)
        {
            int cur = nums[i];

            int need = target - cur;
            if (need == cur)
            {
                if (mem[need].size() > 1)
                {
                    return mem[need];
                }
            }
            else
            {
                if (mem.find(need) != mem.end())
                {
                    return {i, mem[need][0]};
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> answer = solution.twoSum(nums, target);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i != answer.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
