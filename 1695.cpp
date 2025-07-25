#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        unordered_map<int, int> memories;
        int left = 0, right = 0, count = 0;
        while (right < size)
        {
            int current = nums[right++];
            memories[current]++;
            count += current;

            if (memories[current] == 2)
            {
                // 有重复
                while (memories[current] > 1)
                {
                    memories[nums[left]]--;
                    count -= nums[left++];
                }
            }

            answer = max(answer, count);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{5, 2, 1, 2, 5, 2, 1, 2, 5};

    int answer = solution.maximumUniqueSubarray(nums);
    cout << answer << endl;

    return 0;
}
