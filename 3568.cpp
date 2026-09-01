#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    struct State
    {
        int x, y, mask, e;

        State() : x(0), y(0), mask(0), e(0) {}
        State(int a, int b, int c, int d) : x(a), y(b), mask(c), e(d) {}
    };

    int m, n;                        // classroom 的边界
    int total = 0;                   // 当 mask==total 时表示所有垃圾已经清理
    vector<string> room;             // 教室布局
    unordered_map<int, int> litters; // 所有垃圾的编号
    vector<vector<vector<int>>> mem; // 记录到当前状态的最大能量

    // 上下左右
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int x, int y, int mask, int e)
    {
        queue<State> q;
        q.push(State(x, y, mask, e));
        mem[x][y][mask] = e; // 记录初始状态
        int step = 0;        // 记录操作步数

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                State curent = q.front();
                q.pop();
                int a = curent.x;
                int b = curent.y;
                int ma = curent.mask;
                int en = curent.e;

                if (ma == total)
                {
                    return step;
                }

                char cur = room[a][b];
                if (en == 0 && cur != 'R')
                {
                    continue;
                }

                for (int i = 0; i < 4; i++)
                {
                    pair<int, int> dir = dirs[i];
                    int c = a + dir.first;
                    int d = b + dir.second;

                    if ((0 <= c && c < m) && (0 <= d && d < n))
                    {
                        State next(c, d, ma, en);
                        char ch = room[c][d];
                        if (ch == 'X')
                        {
                            continue;
                        }

                        // 更新 mask 和 e
                        if (ch == 'R')
                        {
                            next.e = e;
                        }
                        else
                        {
                            next.e--;
                            if (ch == 'L')
                            {
                                next.mask |= 1 << litters[c * n + d];
                            }
                        }

                        // 如果在当前状态下，剩余的 e 比记忆的多，则更新记忆
                        if (next.e > mem[c][d][next.mask])
                        {
                            mem[c][d][next.mask] = next.e;
                            q.push(next);
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }

public:
    int minMoves(vector<string> &classroom, int energy)
    {
        int answer = 0;
        room = classroom;

        m = classroom.size();
        n = classroom[0].length();

        int sx = -1, sy = -1;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            string &cur = classroom[i];
            for (int j = 0; j < n; j++)
            {
                char c = cur[j];
                if (c == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if (c == 'L')
                {
                    litters[i * n + j] = count++;
                }
            }
        }
        if (count == 0)
        {
            return 0;
        }
        total = (1 << count) - 1;
        mem.resize(m, vector<vector<int>>(n, vector<int>(total + 1, -1)));

        answer = bfs(sx, sy, 0, energy);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> classroom = {"S.", "XL"};
    int energy = 2;

    int answer = solution.minMoves(classroom, energy);
    cout << answer << endl;

    return 0;
}
