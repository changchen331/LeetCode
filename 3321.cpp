#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    using pii = pair<int, int>;
    set<pii> L, R;
    long long sum_l = 0;
    unordered_map<int, int> count;

    void add(int x)
    {
        pii p = {count[x], x};
        if (p.first == 0)
            return;

        if (!L.empty() && p > *L.begin())
        {
            sum_l += (long long)p.first * p.second;
            L.insert(p);
        }
        else
            R.insert(p);
    }

    void del(int x)
    {
        pii p = {count[x], x};
        if (p.first == 0)
            return;

        auto it = L.find(p);
        if (it != L.end())
        {
            sum_l -= (long long)p.first * p.second;
            L.erase(p);
        }
        else
            R.erase(p);
    }

    void l2r()
    {
        pii p = *L.begin();
        sum_l -= (long long)p.first * p.second;

        L.erase(p);
        R.insert(p);
    }

    void r2l()
    {
        pii p = *R.rbegin();
        sum_l += (long long)p.first * p.second;

        R.erase(p);
        L.insert(p);
    }

public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int size = nums.size();
        vector<long long> answer(size - k + 1);

        for (int r = 0; r < size; r++)
        {
            // 添加
            int in = nums[r];
            del(in);
            count[in]++;
            add(in);

            int l = r - k + 1;
            if (l < 0)
                continue;

            // 维护大小
            while (!R.empty() && L.size() < x)
                r2l();
            while (L.size() > x)
                l2r();
            answer[l] = sum_l;

            // 移除
            int out = nums[l];
            del(out);
            count[out]--;
            add(out);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6;
    int x = 2;

    vector<long long> answer = solution.findXSum(nums, k, x);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
