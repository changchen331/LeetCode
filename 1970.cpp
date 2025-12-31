#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class UnionFind
{
    vector<int> fa; // 代表元

public:
    UnionFind(int n) : fa(n)
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

    // 判断 x 和 y 是否在同一个集合
    bool is_same(int x, int y)
    {
        // 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        // 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return find(x) == find(y);
    }

    // 把 from 所在集合合并到 to 所在集合中
    void merge(int from, int to)
    {
        int x = find(from), y = find(to);
        fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
    }
};

class Solution
{
private:
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 左右上下

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int answer = 0, size = cells.size();

        int top = row * col;
        int bot = top + 1;
        UnionFind uf(top + 2);
        vector<vector<int>> land(row, vector<int>(col));

        for (int day = size - 1;; day--)
        {
            vector<int> &cell = cells[day];
            int r = cell[0] - 1;
            int c = cell[1] - 1;
            int v = r * col + c;
            land[r][c] = true; // 变成陆地

            if (r == 0)
                uf.merge(v, top); // 与最上边相连
            if (r == row - 1)
                uf.merge(v, bot); // 与最下边相连

            for (auto &&d : DIRS)
            {
                int x = r + d[0], y = c + d[1];
                if (0 <= x && x < row && 0 <= y && y < col && land[x][y])
                    uf.merge(v, x * col + y); // 与四周的陆地相连
            }

            if (uf.is_same(top, bot))
                return day; // 最上边和最下边连通
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int row = 2;
    int col = 2;
    vector<vector<int>> cells = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};

    int answer = solution.latestDayToCross(row, col, cells);
    cout << answer << endl;

    return 0;
}
