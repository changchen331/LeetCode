#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<vector<int>>> memories;

    int dfs(vector<vector<int>> &coins, int x, int y, int k)
    {
        if (x < 0 || y < 0)
        {
            return INT_MIN;
        }

        int current = coins[x][y];
        if (x == 0 && y == 0)
        {
            return memories[x][y][k] = k ? max(current, 0) : current;
        }

        int &response = memories[x][y][k];
        if (response != INT_MIN)
        {
            return response;
        }

        // 选
        response = max(dfs(coins, x - 1, y, k), dfs(coins, x, y - 1, k)) + current;
        // 不选
        if (k && current < 0)
        {
            response = max(response, max(dfs(coins, x - 1, y, k - 1), dfs(coins, x, y - 1, k - 1)));
        }

        return response;
    }

public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int answer = 0;
        int m = coins.size(), n = coins[0].size();
        memories = vector(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        answer = dfs(coins, m - 1, n - 1, 2);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> coins = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};

    int answer = solution.maximumAmount(coins);
    cout << answer << endl;

    return 0;
}
