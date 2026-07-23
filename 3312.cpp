#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int size = 50'001;
        int size_n = nums.size();
        int size_q = queries.size();
        vector<int> answer(size_q, 0);

        // 方法一（超时）
        // vector<int> gcds;
        // for (int i = 0; i < size_n - 1; i++)
        // {
        //     int l = nums[i];
        //     for (int j = i + 1; j < size_n; j++)
        //     {
        //         int r = nums[j];
        //         gcds.push_back(gcd(l, r));
        //     }
        // }
        // sort(gcds.begin(), gcds.end());
        // for (int i = 0; i < size_q; i++)
        // {
        //     int q = queries[i];
        //     answer[i] = gcds[q];
        // }

        // 方法二
        // 统计各个数字出现频率
        vector<int> feq(size, 0);
        for (auto &&num : nums)
        {
            feq[num]++;
        }

        // 统计公因数
        vector<long long> cnt(size, 0);
        for (int i = 1; i < size; i++)
        {
            int temp = i;
            while (temp < size)
            {
                cnt[i] += feq[temp];
                temp += i;
            }
        }
        for (auto &&kc : cnt)
        {
            kc = kc * (kc - 1) / 2;
        }

        // 统计最大公因数
        for (int i = size - 1; i > 0; i--)
        {
            int temp = i + i;
            while (temp < size)
            {
                cnt[i] -= cnt[temp];
                temp += i;
            }
        }

        // 计算前缀和
        for (int i = 1; i < size; i++)
        {
            cnt[i] += cnt[i - 1];
        }

        // 二分搜索答案
        for (int i = 0; i < size_q; i++)
        {
            long long q = queries[i];
            auto p = upper_bound(cnt.begin(), cnt.end(), q);
            answer[i] = p - cnt.begin();
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 4};
    vector<long long> queries = {0, 2, 2};

    vector<int> answer = solution.gcdValues(nums, queries);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
