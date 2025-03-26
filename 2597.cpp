#include <cmath>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int answer, size;
    unordered_map<int, int> subset;

    void dfs(vector<int> &nums, int k, int position)
    {
        if (position == size)
        {
            answer++;
            return;
        }

        dfs(nums, k, position + 1);
        int current = nums[position];
        if (subset[current - k] == 0 && subset[current + k] == 0)
        {
            subset[current]++;
            dfs(nums, k, position + 1);
            subset[current]--;
        }
    }

public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        size = nums.size();

        // 我的解法
        // answer = size;
        // int limit = 1 << size;
        // for (int i = 3, count = 2; i < limit; i++)
        // {
        //     if (i == 1 << count)
        //     {
        //         count++;
        //         continue;
        //     }

        //     unordered_map<int, int> sub_set;
        //     bool accepted = true;
        //     for (int j = i, temp = 0; j > 0; j >>= 1, temp++)
        //     {
        //         if (j & 1)
        //         {
        //             int num = nums[temp];
        //             if (sub_set[num + k] > 0 || sub_set[num - k] > 0)
        //             {
        //                 accepted = false;
        //                 break;
        //             }
        //             sub_set[num]++;
        //         }
        //     }
        //     answer += accepted;
        // }
        // return answer;

        // 官解
        answer = -1;
        dfs(nums, k, 0);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{141, 167, 169, 162, 144, 159, 143, 168, 140, 147};
    int k = 109;

    int answer = solution.beautifulSubsets(nums, k);
    cout << answer << endl;

    return 0;
}
