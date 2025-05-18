#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;

class Solution
{
private:
    int dfs(vector<vector<int>> &memories, vector<vector<int>> &nxt, int i, int j)
    {
        if (i == 0)
            return 1;

        int &res = memories[i][j];
        if (res != -1)
            return res;
        res = 0;

        for (auto &&k : nxt[j])
            res = (res + dfs(memories, nxt, i - 1, k)) % MOD;
        return res;
    }

public:
    int colorTheGrid(int m, int n)
    {
        long long answer = 0;

        vector<int> pow3(m, 0);
        pow3[0] = 1;
        for (int i = 1; i < m; i++)
            pow3[i] = pow3[i - 1] * 3;

        vector<int> valid;
        for (int color = 0; color < pow3[m - 1] * 3; color++)
        {
            bool ok = true;
            for (int i = 1; i < m; i++)
            {
                if (color / pow3[i] % 3 == color / pow3[i - 1] % 3)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                valid.push_back(color);
        }

        int nv = valid.size();
        vector<vector<int>> nxt(nv, vector<int>(0, 0));
        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv; j++)
            {
                bool ok = true;
                for (int k = 0; k < m; k++)
                {
                    if (valid[i] / pow3[k] % 3 == valid[j] / pow3[k] % 3)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    nxt[i].push_back(j);
            }
        }

        vector<vector<int>> memories(n, vector<int>(nv, -1));
        for (int j = 0; j < nv; j++)
            answer += dfs(memories, nxt, n - 1, j);
        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int m = 5;
    int n = 1000;

    int answer = solution.colorTheGrid(m, n);
    cout << answer << endl;

    return 0;
}
