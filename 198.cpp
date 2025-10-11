#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> money;
    vector<int> memories;

    int dfs(int position)
    {
        if (position < 0)
            return 0;
        if (memories[position] != -1)
            return memories[position];

        int &memory = memories[position];
        memory = max(dfs(position - 1), dfs(position - 2) + money[position]);
        return memory;
    }

public:
    int rob(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        money = nums;
        memories.resize(size, -1);

        answer = dfs(size - 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};

    int answer = solution.rob(nums);
    cout << answer << endl;

    return 0;
}
