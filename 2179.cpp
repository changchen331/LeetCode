#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class FenwickTree
{
private:
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    void update(int i, T val)
    {
        for (; i < tree.size(); i += i & -i)
            tree[i] += val;
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    T pre(int i) const
    {
        T res = 0;
        for (; i > 0; i &= i - 1)
            res += tree[i];
        return res;
    }
};

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[nums1[i]] = i;

        long long ans = 0;
        FenwickTree<int> t(n);
        for (int i = 0; i < n - 1; i++)
        {
            int y = p[nums2[i]];
            int less = t.pre(y);
            ans += 1LL * less * (n - 1 - y - (i - less));
            t.update(y + 1, 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {2, 0, 1, 3};
    vector<int> nums2 = {0, 1, 2, 3};

    long long answer = solution.goodTriplets(nums1, nums2);
    cout << answer << endl;

    return 0;
}
