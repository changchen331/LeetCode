#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long answer = 0;
        int size = nums.size();

        auto maximum = max_element(nums.begin(), nums.end());
        for (int left = 0, right = 0, count = 0;; right++)
        {
            count += (nums[right] == *maximum);
            while (count >= k)
            {
                answer += size - right;
                count -= (nums[left++] == *maximum);
            }

            if (right + 1 == size && count < k)
                break;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 3, 2, 3, 3};
    int k = 2;

    long long answer = solution.countSubarrays(nums, k);
    cout << answer << endl;

    return 0;
}
