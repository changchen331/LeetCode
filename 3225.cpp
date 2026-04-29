#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int size;
    vector<vector<long long>> col_sum;
    vector<vector<vector<long long>>> memories;

    long long dfs(int j, int pre, int dec)
    {
        // pre 表示第 j+1 列的黑格个数
        // dec=true 意味着第 j+1 列的黑格个数 (pre) < 第 j+2 列的黑格个数
        if (j < 0)
        {
            return 0;
        }

        auto &resp = memories[j][pre][dec];
        if (resp != -1)
        {
            return resp;
        }

        // 枚举第 j 列有 cur 个黑格
        resp = 0;
        for (int cur = 0; cur <= size; cur++)
        {
            if (cur == pre)
            {
                // 情况一：相等
                // 没有可以计入总分的格子
                resp = max(resp, dfs(j - 1, cur, 0));
            }
            else if (cur < pre)
            {
                // 情况二：右边黑格多
                // 第 j 列的第 [cur, pre) 行的格子可以计入总分
                resp = max(resp, dfs(j - 1, cur, 1) + col_sum[j][pre] - col_sum[j][cur]);
            }
            else if (dec == 0)
            {
                // 情况三：cur > pre >= 第 j+2 列的黑格个数
                // 第 j+1 列的第 [pre, cur) 行的格子可以计入总分
                resp = max(resp, dfs(j - 1, cur, 0) + col_sum[j + 1][cur] - col_sum[j + 1][pre]);
            }
            else if (pre == 0)
            {
                // 情况四（凹形）：cur > pre < 第 j+2 列的黑格个数
                // 此时第 j+2 列全黑最优（递归过程中一定可以枚举到这种情况）
                // 第 j+1 列全白是最优的，所以只需考虑 pre=0 的情况
                // 由于第 j+1 列在 dfs(j+1) 的情况二中已经统计过，这里不重复统计
                resp = max(resp, dfs(j - 1, cur, 0));
            }
        }

        return resp;
    }

public:
    long long maximumScore(vector<vector<int>> &grid)
    {
        long long answer = 0;
        size = grid.size();

        // 每列的前缀和
        col_sum.resize(size, vector<long long>(size + 1));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                col_sum[i][j + 1] = col_sum[i][j] + grid[j][i];
            }
        }

        // dfs
        memories.resize(size - 1, vector<vector<long long>>(size + 1, {-1, -1}));
        for (int i = 0; i <= size; i++)
        {
            answer = max(answer, dfs(size - 2, i, 0));
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 0, 0, 0},
                                {0, 0, 3, 0, 0},
                                {0, 1, 0, 0, 0},
                                {5, 0, 0, 3, 0},
                                {0, 0, 0, 0, 2}};

    long long answer = solution.maximumScore(grid);
    cout << answer << endl;

    return 0;
}
