#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int answer = 0;

        int size = nums.size();
        unordered_map<int, int> mem;

        int l = 0, r = 0;
        for (; r < size; r++)
        {
            int cur = nums[r];
            mem[cur]++;

            if (mem[cur] > k)
            {
                answer = max(answer, r - l);
                while (mem[cur] > k)
                {
                    int temp = nums[l++];
                    mem[temp]--;
                }
            }
        }
        answer = max(answer, r - l);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    int answer = solution.maxSubarrayLength(nums, k);
    cout << answer << endl;

    return 0;
}
