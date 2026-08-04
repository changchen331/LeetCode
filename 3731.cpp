#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer;

        int mini = INT_MAX, maxi = INT_MIN;
        unordered_map<int, int> mem;
        for (int i = 0; i < size; i++)
        {
            int cur = nums[i];
            mini = min(mini, cur);
            maxi = max(maxi, cur);
            mem[cur]++;
        }

        for (int i = mini + 1; i < maxi; i++)
        {
            if (mem.find(i) == mem.end())
            {
                answer.emplace_back(i);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 31};

    vector<int> answer = solution.findMissingElements(nums);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
