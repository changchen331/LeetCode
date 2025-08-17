#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class Solution
{
private:
    int total = 0, pass = 0;
    void dfs(int current, int n, int k, int maxPts)
    {
        if (current >= k)
        {
            pass += (current <= n);
            total++;
            return;
        }

        for (int i = 1; i <= maxPts; i++)
            dfs(current + i, n, k, maxPts);
    }

public:
    double new21Game(int n, int k, int maxPts)
    {
        double answer = 0.0;

        // 我的方法，指数爆炸
        // dfs(0, n, k, maxPts);
        // answer = 1.0 * pass / total;

        // 官解
        vector<double> dp(n + 1);
        double s = 0;
        for (int i = n; i >= 0; i--)
        {
            dp[i] = i >= k ? 1 : s / maxPts;
            s += dp[i];
            if (i + maxPts <= n)
                s -= dp[i + maxPts];
        }
        answer = dp[0];

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 21;
    int k = 17;
    int maxPts = 10;

    double answer = solution.new21Game(n, k, maxPts);
    cout << fixed << setprecision(5) << answer << endl;

    return 0;
}
