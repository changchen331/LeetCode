#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int answer = 0;
        int size = nums.size();

        vector<long long> suf(size, nums[0]);
        for (int i = 1; i < size; i++)
        {
            suf[i] = suf[i - 1] + nums[i];
        }

        // 方法一（超时）
        // for (int l = 0; l < size; l++)
        // {
        //     int left = l > 0 ? suf[l - 1] : 0;
        //     for (int r = l; r < size; r++)
        //     {
        //         answer += suf[r] - left == k;
        //     }
        // }

        // 方法二
        unordered_map<int, int> mem;
        mem[0]++;
        for (int r = 0; r < size; r++)
        {
            if (mem.find(suf[r] - k) != mem.end())
            {
                answer += mem[suf[r] - k];
            }
            mem[suf[r]]++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> num = {1, 2, 3};
    int k = 3;

    int answer = solution.subarraySum(num, k);
    cout << answer << endl;

    return 0;
}
