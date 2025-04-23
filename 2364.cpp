#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long answer = 0;
        int size = nums.size();

        vector<int> computed_nums(size, 0);
        for (int i = 0; i < size; i++)
            computed_nums[i] = nums[i] - i;
        sort(computed_nums.begin(), computed_nums.end());

        answer = 1LL * size * (size - 1) / 2;
        int count = 0;
        for (int i = 1, last = computed_nums[0]; i < size; i++)
        {
            int current = computed_nums[i];

            if (count > 0 && current != last)
            {
                answer -= (1 + count) * count / 2;
                count = 0;
            }
            else if (current == last)
                count++;

            last = current;
        }

        return answer - 1LL * (1 + count) * count / 2;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5};

    long long answer = solution.countBadPairs(nums);
    cout << answer << endl;

    return 0;
}
