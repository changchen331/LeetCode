#include <array>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 官解
class Solution
{
    // 913. 猫和老鼠
    int catMouseGame(vector<vector<int>> &g_mouse, vector<vector<int>> &g_cat, int mouse_start, int cat_start, int hole)
    {
        int n = g_mouse.size();
        vector<vector<array<int, 2>>> deg(n, vector<array<int, 2>>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                deg[i][j][0] = g_mouse[i].size();
                deg[i][j][1] = g_cat[j].size();
            }
        }
        vector<vector<array<int, 2>>> winner(n, vector<array<int, 2>>(n));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++)
        {
            winner[hole][i][1] = 1;                // 鼠到达洞中（此时轮到猫移动），鼠获胜
            winner[i][hole][0] = 2;                // 猫到达洞中（此时轮到鼠移动），猫获胜
            winner[i][i][0] = winner[i][i][1] = 2; // 猫和鼠出现在同一个节点，无论轮到谁移动，都是猫获胜
            q.emplace(hole, i, 1);
            q.emplace(i, hole, 0);
            q.emplace(i, i, 0);
            q.emplace(i, i, 1);
        }

        // 获取 (mouse, cat, turn) 的上个状态（值尚未确定）
        auto get_pre_states = [&](int mouse, int cat, int turn)
        {
            vector<pair<int, int>> pre_states;
            if (turn == 0)
            { // 当前轮到鼠移动
                for (int pre_cat : g_cat[cat])
                    // 上一轮猫的位置
                    if (winner[mouse][pre_cat][1] == 0)
                        pre_states.emplace_back(mouse, pre_cat);
            }
            else
            { // 当前轮到猫移动
                for (int pre_mouse : g_mouse[mouse])
                    // 上一轮鼠的位置
                    if (winner[pre_mouse][cat][0] == 0)
                        pre_states.emplace_back(pre_mouse, cat);
            }
            return pre_states;
        };

        while (!q.empty())
        {
            auto [mouse, cat, turn] = q.front();
            q.pop();
            int win = winner[mouse][cat][turn]; // 最终谁赢了
            int pre_turn = turn ^ 1;
            for (auto [pre_mouse, pre_cat] : get_pre_states(mouse, cat, turn))
            {
                // 情况一：如果上一回合鼠从 pre 移动到 cur，最终鼠赢，那么标记 pre 状态的 winner = 鼠
                // 情况二：如果上一回合猫从 pre 移动到 cur，最终猫赢，那么标记 pre 状态的 winner = 猫
                // 情况三：如果上一回合鼠从 pre 移动到 cur，最终猫赢，那么待定，直到我们发现从 pre 出发能到达的状态都是猫赢，那么标记 pre 状态的 winner = 猫
                // 情况四：如果上一回合猫从 pre 移动到 cur，最终鼠赢，那么待定，直到我们发现从 pre 出发能到达的状态都是鼠赢，那么标记 pre 状态的 winner = 鼠
                if (pre_turn == win - 1 || --deg[pre_mouse][pre_cat][pre_turn] == 0)
                {
                    winner[pre_mouse][pre_cat][pre_turn] = win;
                    q.emplace(pre_mouse, pre_cat, pre_turn); // 继续倒推
                }
            }
        }

        // 鼠在节点 mouse_start，猫在节点 cat_start，当前轮到鼠移动
        return winner[mouse_start][cat_start][0]; // 返回最终谁赢了（或者平局）
    }

public:
    bool canMouseWin(vector<string> &grid, int catJump, int mouseJump)
    {
        static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 左右上下
        int m = grid.size(), n = grid[0].size();
        // 鼠和猫分别建图
        vector<vector<int>> g_mouse(m * n), g_cat(m * n);
        int mx, my, cx, cy, fx, fy;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '#')
                    continue; // 墙
                if (grid[i][j] == 'M')
                { // 鼠的位置
                    mx = i;
                    my = j;
                }
                else if (grid[i][j] == 'C')
                { // 猫的位置
                    cx = i;
                    cy = j;
                }
                else if (grid[i][j] == 'F')
                { // 食物（洞）的位置
                    fx = i;
                    fy = j;
                }

                int v = i * n + j; // 二维坐标 (i,j) 映射为一维坐标 v
                for (auto [dx, dy] : DIRS)
                { // 枚举左右上下四个方向
                    for (int k = 0; k <= mouseJump; k++)
                    { // 枚举跳跃长度
                        int x = i + k * dx, y = j + k * dy;
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#')
                            // 出界或者遇到墙
                            break;
                        g_mouse[v].push_back(x * n + y); // 连边
                    }
                    for (int k = 0; k <= catJump; k++)
                    { // 枚举跳跃长度
                        int x = i + k * dx, y = j + k * dy;
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#')
                            // 出界或者遇到墙
                            break;
                        g_cat[v].push_back(x * n + y); // 连边
                    }
                }
            }
        }
        // 判断是否鼠赢
        return catMouseGame(g_mouse, g_cat, mx * n + my, cx * n + cy, fx * n + fy) == 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> grid{"####F", "#C...", "M...."};
    int catJump = 1;
    int mouseJump = 2;

    bool answer = solution.canMouseWin(grid, catJump, mouseJump);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
