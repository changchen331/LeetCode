#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> NUMS, MEMORIES, FROM;
    int dfs(int i)
    {
        int &response = MEMORIES[i];
        if (response)
            return response;

        for (int j = 0; j < i; j++)
        {
            if (NUMS[i] % NUMS[j])
                continue;

            int f = dfs(j);
            if (f > response)
            {
                response = f;
                FROM[i] = j;
            }
        }
        return ++response;
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> answer;
        int size = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> memories(size), from(size, -1);
        NUMS = nums;
        MEMORIES = memories;
        FROM = from;

        int max_f = 0, max_i = 0;
        for (int i = 0; i < size; i++)
        {
            int f = dfs(i);
            if (f > max_f)
            {
                max_f = f;
                max_i = i;
            }
        }

        for (int i = max_i; i >= 0; i = FROM[i])
            answer.push_back(nums[i]);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 4, 8};

    vector<int> answer = solution.largestDivisibleSubset(nums);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
