#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int answer = 0;
        int size = nums.size();

        set<pair<long long, int>> pairs; // (相邻元素和，左边那个数的下标)
        int dec = 0;
        for (int i = 0; i < size - 1; i++)
        {
            int x = nums[i], y = nums[i + 1];
            dec += x > y;
            pairs.emplace(x + y, i);
        }

        set<int> idx; // 剩余下标
        for (int i = 0; i < size; i++)
            idx.insert(i);

        vector<long long> a(nums.begin(), nums.end());
        while (dec > 0)
        {
            answer++;

            // 删除相邻元素和最小的一对
            auto [s, i] = *pairs.begin();
            pairs.erase(pairs.begin());

            auto it = idx.lower_bound(i);

            // (当前元素，下一个数)
            auto nxt_it = next(it);
            int nxt = *nxt_it;
            dec -= a[i] > a[nxt]; // 旧数据

            // (前一个数，当前元素)
            if (it != idx.begin())
            {
                int pre = *prev(it);
                dec -= a[pre] > a[i]; // 旧数据
                dec += a[pre] > s;    // 新数据
                pairs.erase({a[pre] + a[i], pre});
                pairs.emplace(a[pre] + s, pre);
            }

            // (下一个数，下下一个数)
            auto nxt2_it = next(nxt_it);
            if (nxt2_it != idx.end())
            {
                int nxt2 = *nxt2_it;
                dec -= a[nxt] > a[nxt2]; // 旧数据
                dec += s > a[nxt2];      // 新数据（当前元素，下下一个数）
                pairs.erase({a[nxt] + a[nxt2], nxt});
                pairs.emplace(s + a[nxt2], i);
            }

            a[i] = s;       // 把 a[nxt] 加到 a[i] 中
            idx.erase(nxt); // 删除 nxt
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 2, 3, 1};

    int answer = solution.minimumPairRemoval(nums);
    cout << answer << endl;

    return 0;
}
