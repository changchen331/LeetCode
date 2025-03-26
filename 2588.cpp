#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        long long answer = 0;
        unordered_map<int, int> count{{0, 1}};

        int temp = 0;
        for (auto &&num : nums)
        {
            temp ^= num;
            answer += count[temp]++;
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {18, 16, 20, 4, 14, 6, 2, 20};

    long long answer = solution.beautifulSubarrays(nums);
    cout << answer << endl;

    return 0;
}
