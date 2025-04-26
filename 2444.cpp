#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long answer = 0;
        int size = nums.size();

        int min_i = -1, max_i = -1, exclude = -1;
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            if (num == minK)
                min_i = i;
            if (num == maxK)
                max_i = i;
            if (num < minK || num > maxK)
                exclude = i;
            answer += max(min(min_i, max_i) - exclude, 0);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 1, 1, 1};
    int minK = 1;
    int maxK = 1;

    long long answer = solution.countSubarrays(nums, minK, maxK);
    cout << answer << endl;

    return 0;
}
