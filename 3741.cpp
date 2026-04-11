#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        int answer = INT_MAX;
        int size = nums.size();

        unordered_map<int, vector<int>> counts;
        for (int i = 0; i < size; i++)
        {
            counts[nums[i]].push_back(i);
        }

        for (auto &&count : counts)
        {
            auto [num, pos] = count;
            if (pos.size() < 3)
            {
                continue;
            }

            for (int i = 2; i < pos.size(); i++)
            {
                int temp = 2 * (pos[i] - pos[i - 2]);
                answer = min(answer, temp);
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 2, 1, 2};

    int answer = solution.minimumDistance(nums);
    cout << answer << endl;

    return 0;
}
