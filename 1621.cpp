#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;
    vector<vector<vector<long long>>> mem;

    long long dfs(int n, int k, int p, bool end)
    {
        if (k == 0)
        {
            if (end)
            {
                return 0; // 找终点
            }
            else
            {
                return 1; // 找起点
            }
        }

        long long &resp = mem[p][k][end];
        if (resp != -1)
        {
            return resp;
        }

        resp = 0;
        if (end)
        {
            // 找终点
            for (int i = p + 1; i < n; i++)
            {
                resp += dfs(n, k - 1, i, false) % MOD;
            }
        }
        else
        {
            // 找起点
            for (int i = p; i < n; i++)
            {
                resp += dfs(n, k, i, true) % MOD;
            }
        }

        return resp;
    }

public:
    int numberOfSets(int n, int k)
    {
        long long answer = 0;

        // 方法一（超时)
        //  mem = vector(n, vector<vector<long long>>(k + 1, vector<long long>(2, -1)));
        //  answer = dfs(n, k, 0, false);

        // 方法二
        vector<long long> c(n, 1), o(n, 0);
        for (int i = 0; i < k; i++)
        {
            long long suf = 0;
            for (int p = n - 1; p > -1; p--)
            {
                o[p] = suf;
                suf = (suf + c[p]) % MOD;
            }

            suf = 0;
            for (int p = n - 1; p > -1; p--)
            {
                suf = (suf + o[p]) % MOD;
                c[p] = suf;
            }
        }

        answer = c[0];
        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 4;
    int k = 2;

    int answer = solution.numberOfSets(n, k);
    cout << answer << endl;

    return 0;
}
