#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long answer = 0;
        int size = nums.size();

        int left = 0, right = 0;
        long long score = 0;
        while (right < size)
        {
            score += nums[right];
            while (score * (right - left + 1) >= k)
            {
                answer += right - left;
                score -= nums[left++];
            }
            right++;
        }

        answer += 1L * (right - left) * (right - left + 1) / 2;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 1, 4, 3, 5};
    long long k = 10;

    long long answer = solution.countSubarrays(nums, k);
    cout << answer << endl;

    return 0;
}
