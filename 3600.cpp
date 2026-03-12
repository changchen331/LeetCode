#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class UnionFind
{
private:
    vector<int> fa; // 代表元

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), cc(n)
    {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己
        iota(fa.begin(), fa.end(), 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x)
    {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x)
            fa[x] = find(fa[x]); // fa 改成代表元

        return fa[x];
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to)
    {
        int x = find(from), y = find(to);
        if (x == y)
            return false; // from 和 to 在同一个集合，不做合并

        fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        cc--;      // 成功合并，连通块个数减一
        return true;
    }
};

class Solution
{
private:
    bool check(int n, vector<vector<int>> &edges, int k, int low)
    {
        UnionFind u(n);
        for (auto &&edge : edges)
        {
            int x = edge[0], y = edge[1], s = edge[2], must = edge[3];
            if (must && s < low)
                return false;

            if (must || s >= low)
                u.merge(x, y);
        }

        int left_k = k;
        for (auto &&edge : edges)
        {
            if (left_k == 0 || u.cc == 1)
                break;

            int x = edge[0], y = edge[1], s = edge[2], must = edge[3];
            if (!must && s < low && s * 2 >= low && u.merge(x, y))
                left_k--;
        }

        return u.cc == 1;
    }

public:
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        int answer = 0;

        UnionFind must_uf(n);
        UnionFind all_uf(n);
        int min_s = INT_MAX, max_s = 0;
        for (auto &&edge : edges)
        {
            int x = edge[0], y = edge[1], s = edge[2], must = edge[3];
            if (must && !must_uf.merge(x, y))
                return -1;

            all_uf.merge(x, y);
            min_s = min(min_s, s);
            max_s = max(max_s, s);
        }

        if (all_uf.cc > 1)
            return -1;

        int left = min_s, right = max_s * 2;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (check(n, edges, k, mid))
                left = mid;
            else
                right = mid - 1;
        }

        answer = left;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    vector<vector<int>> edges = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    int k = 1;

    int answer = solution.maxStability(n, edges, k);
    cout << answer << endl;

    return 0;
}
