#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1'000'000'007;
const int MX = 100'000;

vector<int> pow_2(MX, 0);
auto init = []
{
    pow_2[0] = 1;
    for (int i = 1; i < MX; i++)
        pow_2[i] = (pow_2[i - 1] * 2) % MOD;
    return 0;
}();

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        long long answer = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        int head = 0, tail = size - 1;
        while (head <= tail)
        {
            if (nums[head] + nums[tail] <= target)
                answer += pow_2[tail - head++];
            else
                tail--;
        }

        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 3, 6, 8};
    int target = 10;

    int answer = solution.numSubseq(nums, target);
    cout << answer << endl;

    return 0;
}
