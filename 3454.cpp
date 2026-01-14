#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

class SegmentTree
{
private:
    struct Node
    {
        int l, r;
        int min_cover_len = 0; // 区间内被矩形覆盖次数最少的底边长之和
        int min_cover = 0;     // 区间内被矩形覆盖的最小次数
        int todo = 0;          // 子树内的所有节点的 min_cover 需要增加的量，注意这可以是负数
    };

    vector<Node> seg;

    // 根据左右儿子的信息，更新当前节点的信息
    void maintain(int o)
    {
        Node &lo = seg[o * 2];
        Node &ro = seg[o * 2 + 1];
        int mn = min(lo.min_cover, ro.min_cover);
        seg[o].min_cover = mn;
        // 只统计等于 min_cover 的底边长之和
        seg[o].min_cover_len = (lo.min_cover == mn ? lo.min_cover_len : 0) + (ro.min_cover == mn ? ro.min_cover_len : 0);
    }

    // 仅更新节点信息，不下传懒标记 todo
    void do_(int o, int v)
    {
        seg[o].min_cover += v;
        seg[o].todo += v;
    }

    // 下传懒标记 todo
    void spread(int o)
    {
        int &v = seg[o].todo;
        if (v != 0)
        {
            do_(o * 2, v);
            do_(o * 2 + 1, v);
            v = 0;
        }
    }

    // 建树
    void build(vector<int> &xs, int o, int l, int r)
    {
        seg[o].l = l;
        seg[o].r = r;
        if (l == r)
        {
            seg[o].min_cover_len = xs[l + 1] - xs[l];
            return;
        }
        int m = (l + r) / 2;
        build(xs, o * 2, l, m);
        build(xs, o * 2 + 1, m + 1, r);
        maintain(o);
    }

    // 区间更新
    void update(int o, int l, int r, int v)
    {
        if (l <= seg[o].l && seg[o].r <= r)
        {
            do_(o, v);
            return;
        }
        spread(o);
        int m = (seg[o].l + seg[o].r) / 2;
        if (l <= m)
            update(o * 2, l, r, v);
        if (m < r)
            update(o * 2 + 1, l, r, v);

        maintain(o);
    }

    unsigned int bit_width(unsigned int x)
    {
        if (x == 0)
            return 0;

        unsigned int width = 0;
        while (x)
        {
            width++;
            x >>= 1;
        }
        return width;
    }

public:
    SegmentTree(vector<int> &xs)
    {
        unsigned n = xs.size() - 1; // xs.size() 个横坐标有 xs.size()-1 个差值
        seg.resize(2 << bit_width(n - 1));
        build(xs, 1, 0, n - 1);
    }

    void update(int l, int r, int v)
    {
        update(1, l, r, v);
    }

    int get_uncovered_length()
    {
        return seg[1].min_cover ? 0 : seg[1].min_cover_len;
    }
};

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        double answer = 0;
        vector<int> xs;

        struct Event
        {
            int y, lx, rx, delta;
            Event(int y, int lx, int rx, int delta) : y(y), lx(lx), rx(rx), delta(delta) {}
        };
        vector<Event> events;

        for (auto &sq : squares)
        {
            int lx = sq[0], y = sq[1], l = sq[2];
            int rx = lx + l;
            xs.push_back(lx);
            xs.push_back(rx);
            events.emplace_back(y, lx, rx, 1);
            events.emplace_back(y + l, lx, rx, -1);
        }

        // 排序去重，方便离散化
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        // 初始化线段树
        SegmentTree t(xs);

        // 模拟扫描线从下往上移动
        sort(events.begin(), events.end(), [](const Event &a, const Event &b)
             { return a.y < b.y; });
        vector<pair<long long, int>> records(events.size() - 1);
        long long tot_area = 0;
        for (int i = 0; i + 1 < events.size(); i++)
        {
            auto &[y, lx, rx, delta] = events[i];
            int l = lower_bound(xs.begin(), xs.end(), lx) - xs.begin();     // 离散化
            int r = lower_bound(xs.begin(), xs.end(), rx) - xs.begin() - 1; // r 对应着 xs[r] 与 xs[r+1]=rx 的差值
            t.update(l, r, delta);                                          // 更新被 [lx, rx] 覆盖的次数
            int sum_len = xs.back() - xs[0] - t.get_uncovered_length();     // 减去没被矩形覆盖的长度
            records[i] = {tot_area, sum_len};
            tot_area += 1LL * sum_len * (events[i + 1].y - y); // 新增面积 = 被至少一个矩形覆盖的底边长之和 * 矩形高度
        }

        // 二分找最后一个 < tot_area / 2 的面积
        auto it = lower_bound(records.begin(), records.end(), tot_area,
                              [](const auto &element, const auto &value)
                              { return element.first * 2 < value; });
        int i = it - records.begin() - 1;
        auto [area, sum_len] = records[i];

        answer = events[i].y + (tot_area - area * 2) / (sum_len * 2.0);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> squares = {{0, 0, 1}, {2, 2, 1}};

    double answer = solution.separateSquares(squares);
    cout << fixed << setprecision(5);
    cout << answer << endl;

    return 0;
}
