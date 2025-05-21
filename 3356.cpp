#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool check(vector<int> &nums, vector<vector<int>> &queries, vector<int> decrements, int k)
    {
        for (int i = 0; i < k; i++)
        {
            auto &query = queries[i];
            int l = query[0], r = query[1] + 1, value = query[2];
            decrements[l] += value;
            decrements[r] -= value;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += decrements[i];
            if (nums[i] > sum)
                return false;
        }
        return true;
    }

public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int size = nums.size(), time = queries.size();
        vector<int> decrements(size + 1, 0);

        // 方法一 超时
        // int flag = true;
        // for (auto &&num : nums)
        // {
        //     if (num != 0)
        //     {
        //         flag = false;
        //         break;
        //     }
        // }
        // if (flag)
        //     return 0;

        // for (int round = 0, record = 0; round < time; round++)
        // {
        //     decrements[queries[round][0]] -= queries[round][2];
        //     decrements[queries[round][1] + 1] += queries[round][2];

        //     for (int i = 0, count = 0; i < size; i++)
        //     {
        //         count += decrements[i];
        //         if (nums[i] + count <= 0)
        //             record = i + 1;
        //         else
        //             break;

        //         if (record == size)
        //             return round + 1;
        //     }
        // }

        // 方法二
        int left = -1, right = time + 1;
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            (check(nums, queries, decrements, mid) ? right : left) = mid;
        }

        return right <= time ? right : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{2, 0, 2};
    vector<vector<int>> queries{{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};

    int answer = solution.minZeroArray(nums, queries);
    cout << answer << endl;

    return 0;
}
