#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int MOD = 1'000'000'007;

    pair<int, int> find_boundaries(const vector<int> &nums, int target)
    {
        int max_min = -1, min_max = -1;

        // 查找比目标小的最大数
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                max_min = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        // 查找比目标大的最小数
        left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                min_max = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return {max_min, min_max};
    }

public:
    int specialTriplets(vector<int> &nums)
    {
        long long answer = 0;
        int size = nums.size();

        unordered_map<int, vector<int>> memories;
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            memories[num].push_back(i);
        }

        for (int i = 1; i < size - 1; i++)
        {
            int num = nums[i] * 2;
            if (memories.find(num) == memories.end())
                continue;

            vector<int> &memory = memories[num];
            int length = memory.size();

            pair<int, int> response = find_boundaries(memory, i);
            int min_max = response.first, max_min = response.second;
            if (min_max < 0 || max_min < 0)
                continue;

            answer += 1LL * (min_max + 1) * (length - max_min);
            answer %= MOD;
        }

        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {40, 2, 20, 1, 2};

    int answer = solution.specialTriplets(nums);
    cout << answer << endl;

    return 0;
}
