#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int different(vector<int> &nums, int obesity)
    {
        int count = 0;

        int current = obesity;
        for (auto &&num : nums)
        {
            if (num % 2 == current)
            {
                count++;
                current = 1 - current;
            }
        }

        return count;
    }

public:
    int maximumLength(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        if (size < 3)
            return size;

        vector<int> same(size - 1, -1), diff(size - 1, -1);

        int odd_start = different(nums, 1);
        int eve_start = different(nums, 0);
        answer = max(odd_start, eve_start);

        int count_odd = 0, count_eve = 0;
        for (auto &&num : nums)
            count_odd += num % 2;
        count_eve = size - count_odd;

        answer = max(answer, max(count_eve, count_odd));

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4};

    int answer = solution.maximumLength(nums);
    cout << answer << endl;

    return 0;
}
