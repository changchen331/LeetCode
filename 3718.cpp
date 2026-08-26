#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        int answer = k;

        int size = nums.size();
        unordered_set<int> mem;
        for (int i = 0; i < size; i++)
        {
            mem.insert(nums[i]);
        }

        while (mem.find(answer) != mem.end())
        {
            answer += k;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {8, 2, 3, 4, 6};
    int k = 2;

    int answer = solution.missingMultiple(nums, k);
    cout << answer << endl;

    return 0;
}
