#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long answer = 0;
        int size = nums.size();

        unordered_map<int, int> numbers;
        for (int head = 0, tail = 0, count = 0;;)
        {
            if (count < k)
            {
                if (tail == size)
                    break;
                count += numbers[nums[tail++]]++;
            }
            if (count >= k)
            {
                answer += size - tail + 1;
                count -= --numbers[nums[head++]];
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 1, 4, 3, 2, 2, 4};
    int k = 2;

    long long answer = solution.countGood(nums, k);
    cout << answer << endl;

    return 0;
}
