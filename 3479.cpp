#include <bit>
#include <vector>
#include <iostream>
using namespace std;

class SegmentTree
{
private:
    vector<int> mx;

    void maintain(int o)
    {
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }

    // 初始化线段树
    void build(const vector<int> &a, int o, int l, int r)
    {
        if (l == r)
        {
            mx[o] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(a, o * 2, l, m);
        build(a, o * 2 + 1, m + 1, r);
        maintain(o);
    }

    int bit_width(size_t x)
    {
        if (x == 0)
            return 0; // 0 的位数是 0
        int width = 0;
        while (x >>= 1)
            width++;      // 右移直到 x == 0
        return width + 1; // 最高位 +1
    }

public:
    SegmentTree(const vector<int> &a)
    {
        size_t n = a.size();
        mx.resize(2 << bit_width(n - 1));
        build(a, 1, 0, n - 1);
    }

    // 找区间内的第一个 >= x 的数，并更新为 -1，返回这个数的下标（没有则返回 -1）
    int findFirstAndUpdate(int o, int l, int r, int x)
    {
        if (mx[o] < x)
            return -1; // 区间没有 >= x 的数
        if (l == r)
        {
            mx[o] = -1; // 更新为 -1，表示不能放水果
            return l;
        }

        int m = (l + r) / 2;
        int i = findFirstAndUpdate(o * 2, l, m, x);         // 先递归左子树
        if (i < 0)                                          // 左子树没找到
            i = findFirstAndUpdate(o * 2 + 1, m + 1, r, x); // 再递归右子树
        maintain(o);
        return i;
    }
};

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int answer = 0, size = fruits.size();

        // 我的方法（超时）
        // for (int i = 0; i < size; i++)
        // {
        //     int current = fruits[i];

        //     int position = 0;
        //     for (; position < baskets.size(); position++)
        //         if (current <= baskets[position])
        //             break;

        //     if (position < baskets.size())
        //         // baskets.erase(baskets.begin() + position);
        //         baskets[position] = 0;
        //     else
        //         answer++;
        // }

        // 官解
        SegmentTree t(baskets);
        for (int x : fruits)
            if (t.findFirstAndUpdate(1, 0, size - 1, x) < 0)
                answer++;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> fruits{4, 2, 5};
    vector<int> baskets{3, 5, 4};

    int answer = solution.numOfUnplacedFruits(fruits, baskets);
    cout << answer << endl;

    return 0;
}
