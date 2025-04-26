#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        long long answer = 0;
        int size = nums.size();

        vector<int> computed_nums(size + 1, 0);
        for (int i = 0; i < size; i++)
            computed_nums[i + 1] = computed_nums[i] + (nums[i] % modulo == k);

        vector<int> counts(min(size + 1, modulo), 0);
        for (auto &&c_n : computed_nums)
        {
            if (c_n >= k)
                answer += counts[(c_n - k) % modulo];
            counts[c_n % modulo]++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 1, 9, 6};
    int modulo = 3;
    int k = 0;

    long long answer = solution.countInterestingSubarrays(nums, modulo, k);
    cout << answer << endl;

    return 0;
}
