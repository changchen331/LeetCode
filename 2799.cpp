#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        unordered_map<int, int> counts, haves;
        for (auto &&num : nums)
        {
            haves[num] = 0;
            counts[num]++;
        }

        int quantity = counts.size(), count = 0;
        for (int left = 0, right = 0;;)
        {
            if (count < quantity)
            {
                int numR = nums[right++];
                count += haves[numR]++ == 0;
                counts[numR]--;
            }
            else
            {
                answer += size - right + 1;
                int numL = nums[left++];
                count -= --haves[numL] == 0;
                if (counts[numL] == 0 && haves[numL] == 0)
                    break;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{665, 867, 954, 1411, 728, 1006, 372, 1411};

    int answer = solution.countCompleteSubarrays(nums);
    cout << answer << endl;

    return 0;
}
