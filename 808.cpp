#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class Solution
{
private:
    double dfs(vector<vector<double>> &memories, int a_left, int b_left)
    {
        if (a_left <= 0 && b_left <= 0)
            return 0.5;
        if (a_left <= 0)
            return 1.0;
        if (b_left <= 0)
            return 0.0;

        double &memory = memories[a_left][b_left];
        if (memory == 0)
            memory = (dfs(memories, a_left - 4, b_left - 0) +
                      dfs(memories, a_left - 3, b_left - 1) +
                      dfs(memories, a_left - 2, b_left - 2) +
                      dfs(memories, a_left - 1, b_left - 3)) /
                     4;
        return memory;
    }

public:
    double soupServings(int n)
    {
        if (n > 4450)
            return 1;

        double answer = 0;
        n = ((n + 24) / 25);
        vector<vector<double>> memories(n + 1, vector<double>(n + 1));

        answer = dfs(memories, n, n);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 50;

    double answer = solution.soupServings(n);
    cout << fixed << setprecision(5) << answer << endl;

    return 0;
}
